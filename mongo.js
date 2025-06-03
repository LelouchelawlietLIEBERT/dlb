const express = require('express');
const mongoose = require('mongoose');
const app = express();

app.use(express.json());

mongoose.connect('mongodb+srv://ash:1234@cluster0.ychcmqx.mongodb.net/FinalYears?retryWrites=true&w=majority&appName=Cluster0')
  .then(() => console.log('Connected to MongoDB'))
  .catch(err => console.error('Connection error:', err));

const Student = mongoose.model('Student', {
  USN: String,
  Name: String,
  Company_name: String
});

app.get('/infosys', async (req, res) => {
  try {
    const students = await Student.find({ Company_name: 'Infosys' });
    res.json(students);
  } catch (err) {
    res.status(500).send('Server error');
  }
});

app.listen(3000, () => console.log('Server running on http://localhost:3000/infosys'));
