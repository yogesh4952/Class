#!/bin/bash

# 🚀 Working Directory
echo "📂 Working Directory: $(pwd)"

# 📌 Initialize git only if not already
if [ ! -d ".git" ]; then
  git init
  echo "✅ Git initialized"
fi

# 📌 Add all files
git add .

# 📌 Use provided commit message OR default one
if [ -n "$1" ]; then
  commit_msg="$1"
else
  commit_msg="Auto commit on $(date '+%Y-%m-%d %H:%M:%S')"
fi

git commit -m "$commit_msg"

  
# 📌 Push code to GitHub
git branch -M main
git push -u origin main
