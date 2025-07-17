import express from 'express';

const app = express();

app.get('/', (req, res) => {
  res.send('App is alive');
});

app.listen(8000, () => {
  console.log('Server running succesfully at port 8000');
});
