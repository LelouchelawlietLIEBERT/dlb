const express = require('express');
const nunjucks = require('nunjucks');
const app = express();

nunjucks.configure('views', {
  autoescape: true,
  express: app
});
app.set('view engine', 'njk');

const branches = {
  cse: { name: 'CSE', color: '#d1f2eb', font: 'Arial', desc: 'Focuses on software, AI, and programming.' },
  ece: { name: 'ECE', color: '#f9e79f', font: 'Courier New', desc: 'Deals with electronics and communication.' },
  me:  { name: 'ME',  color: '#f5b7b1', font: 'Georgia', desc: 'Focuses on mechanics and machines.' }
};

app.get('/', (req, res) => res.render('index', { branches }));

app.get('/:branch', (req, res) => {
  const data = branches[req.params.branch];
  data ? res.render('branch', data) : res.status(404).send('Branch not found');
});

app.listen(3000, () => console.log('http://localhost:3000'));
