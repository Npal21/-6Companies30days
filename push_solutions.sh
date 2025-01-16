#!/bin/bash

git pull origin main --rebase
# Get the list of all untracked .cpp files
for file in $(git ls-files --others --exclude-standard -- '*.cpp'); do
    # Add the file to staging
    git add "$file"
    
    # Commit with the default message
    git commit -m "Created $file"
done

# Push the changes to the main branch
git push origin main

