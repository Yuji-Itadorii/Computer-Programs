
date=$(date '+%Y-%m-%d %H:%M:%S')
commit_message="Update: $date"

git add .
git commit -m "$commit_message"
git push 



