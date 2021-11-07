# sstdref
sstdref is the documentation files for SSTD.

URL: https://admiswalker.github.io/sstdref/

## Installation
### In the case with docker
- update
  ```
  $ sudo apt-get update
  ```
- curl
  ```
  $ sudo apt-get install curl
  ```
- Docker
  - Docker engine
    ```
    $ curl -fsSL https://get.docker.com/ | sh
    ```
  - Creation of docker group and adding a user, in order not to required sudo.
    - Creation of docker group
      ```
      $ sudo groupadd docker
      ```
    - Adding a user who want to use docker. In this example, we will add login-user ($USER)
      ```
      $ sudo gpasswd -a $USER docker
      ```
    - Rebooting PC
      ```
      $ reboot
      ```
  - Building the Dockerfile
    ```
    $ cd docker
    $ sh docker_build.sh
    ```
### In the case without docker
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
## Development cycle
- Running the local server
  ```
  $ ./make.sh run  # with Docker
  $ make run  # without Docker
  ```
- Editting documentation under ```sstdref/src/docs```
- Compiling files
  ```
  $ ./make.sh  # with Docker
  $ make -j  # without Docker
  ```
- Checking the local server (http://localhost:8000/).
- Adding the changes to git repository.
  ```
  $ git add .
  $ git commit -m 'comments'
  $ git push origin main
  ```
- Updating the github.io
  ```
  $ ./make.sh updateDocs  # with Docker
  $ make updateDocs # without Docker
  ```

## Commands help
### In the case with docker
```
$ ./make.sh help
Usages:
  $ ./make.sh            : Building the documents
  $ ./make.sh clean      : Removing the temporary files
  $ ./make.sh help       : Showing the help (This messages)
  $ ./make.sh run        : Running the previewing server on a local machine
  $ ./make.sh updateDocs : Updating the documents at github.io
```
### In the case without docker
```
$ make help
Usages:
  make -j         : Building the documents
  make clean      : Removing the temporary files
  make help       : Showing the help (This messages)
  make run        : Running the previewing server on a local machine
  make updateDocs : Updating the documents at github.io
  make updateLib  : Updating the SSTD at "./mdEx_cpp_example"
```

## File and Directory descriptions

| File or directory name | Description Origin |
| ---------------------- | ------------------ |
| docker/                | Dockerfile and the other required files |
| docs/                  | Static files for github.io |
| docs_src/              | Markdown files ***for editing*** and generating static site |
| docs_src/custom_dir/   | Custom CSS and JavaScripts |
| mdEx_cpp_example/      | Markdown expansion to run cpp example code by ```#mdEx: cpp example (in)``` and ```#mdEx: cpp example (out)``` |
| mdEx_title/            | Markdown extension to automatically generate titles |
| tmp/                   | Temporary files to generate docs/ files and previewing by httpd |
| .git/                  | git files          |
| Makefile               | ```$ make run``` for running preview server. ```$ make``` for rebuild preview. ```$ make updateDocs``` for build under ```src``` and update pages on ```github.io``` |
| README.me              | This file          |
| make.sh                | Makefile wrapper for running in Docker |
| template.md            | Template markdown file for docs_src/ |
| .gitignore             | Registering files to ignore in order not to track files on git |

## Trouble shooting
### Case1. Unable to find image 'sstdref_gen:latest' locally
You need to build dockerdile if docker image is not found when running "$ ./make.sh run", using below commands.

```
$ cd docker
$ sh docker_build.sh
```


