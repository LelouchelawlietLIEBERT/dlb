const express = require('express');
const mongoose = require('mongoose');

mongoose.connect('mongodb://127.0.0.1:27017/FinalYears');
const Student = mongoose.model('Student', new mongoose.Schema({
  USN: String, Name: String, Company_name: String
}));

const app = express();
app.use(express.static(__dirname));
app.use(express.urlencoded({ extended: true }));

app.post('/add-student', async (req, res) => {
  await new Student(req.body).save();
  res.redirect('/inx.html');
});

app.get('/infosys-students', async (req, res) => {
  res.json(await Student.find({ Company_name: 'Infosys' }));
});

app.listen(3000, () => console.log('http://localhost:3000/inx.html'));
