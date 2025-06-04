import dotenv from 'dotenv';
dotenv.config();

import express, { Request, Response } from 'express';

const app = express();
const PORT = 3000;

app.use(express.json());

app.get('/', (req: Request, res: Response) => {
  res.json({
    success: true,
    message: 'Hello',
  });
});

app.listen(PORT, () => {
  console.log(`Server is running on port ${PORT}`);
});
