# sstdref
sstdref is the documentation files for SSTD.

URL: https://admiswalker.github.io/sstdref/

# Installation
- mkdocs
  ```
  $ pip install mkdocs
  $ pip install mkdocs-material
  $ pip install mkdocs-awesome-pages-plugin
  ```
- init mkdocs
  ```
  $ mkdocs new src
  ```

# Development cycle
- Running the local server
  ```
  $ make run
  ```
- Editting documentation under ```sstdref/src/docs```
- Checking the local server (http://127.0.0.1:8000/).
- Adding the changes to git repository.
  ```
  $ git add .
  $ git commit -m 'comments'
  $ git push origin main
  ```
- Updating the github.io
  ```
  $ make updateDocs
  ```

# File and Directory descriptions

| File or directory name | Description Origin |
| ---------------------- | ------------------ |
| usages                 | Example code for SSTD documentation |
