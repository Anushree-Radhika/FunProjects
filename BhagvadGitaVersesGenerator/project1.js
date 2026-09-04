let btn = document.querySelector('#new-quote');
let quote = document.querySelector('.quote');
let person = document.querySelector('.person');

const maxVersesPerChapter = [
  47, 72, 43, 42, 29, 47, 30, 28, 34, 
  42, 55, 20, 35, 27, 20, 24, 28, 78
];
async function getRandomGitaVerse() {
  try {
    quote.innerText = "Loading divine wisdom...";
    person.innerText = "";

    let randomChapter = Math.floor(Math.random() * 18) + 1;
    let maxVerses = maxVersesPerChapter[randomChapter - 1]; 
    let randomVerse = Math.floor(Math.random() * maxVerses) + 1;

    const response = await fetch(`https://vedicscriptures.github.io/slok/${randomChapter}/${randomVerse}`);
    
    if (!response.ok) {
        throw new Error("Failed to fetch from API");
    }

    const data = await response.json();
    
    quote.innerText = `"${data.siva.et}"`;
    person.innerText = `- Bhagavad Gita (Chapter ${randomChapter}, Verse ${randomVerse})`;
    
  } catch (error) {
    console.error('Error fetching the Gita verse:', error);
    quote.innerText = "Oops! Could not fetch the verse right now.";
    person.innerText = "";
  }
}
btn.addEventListener('click', getRandomGitaVerse);
getRandomGitaVerse();