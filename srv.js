const express = require('express');
const mongoose = require('mongoose');

mongoose.connect('mongodb://127.0.0.1:27017/cie');
const Student = mongoose.model('Student', new mongoose.Schema({
  USN: String, Name: String,subject_code: String, CIE_marks: Number
}));

const app = express();
app.use(express.static(__dirname));
app.use(express.urlencoded({ extended: true }));

app.post('/ads', async (req, res) => {
  await new Student(req.body).save();
  res.redirect('/indx.html');
});

app.get('/l20', async (req, res) => {
  res.json(await Student.find({ CIE_marks: {$lt:20} }));
});

app.listen(3000, () => console.log('http://localhost:3000/indx.html'));
