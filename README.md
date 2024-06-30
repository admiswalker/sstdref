# sstdref
sstdref is the document files for SSTD ([repository](https://github.com/admiswalker/SubStandardLibrary-SSTD-)).

## View the documents
- Web Viewing  
  https://admiswalker.github.io/sstdref/
- Local Viewing
  1. Copying this repository to your local device.
     ```
     $ git clone git@github.com:admiswalker/sstdref.git
     ```
  2. Clicking the `sstdref/index.html` and opening in your blouser.

## Installation for development
### In the case with docker
1. update
   ```
   $ sudo apt-get update
   ```
2. installing curl
   ```
   $ sudo apt-get install curl
   ```
3. installing Docker
   1. installing Docker engine
      ```
      $ curl -fsSL https://get.docker.com/ | sh
      ```
   2. Creation of docker group and adding a user, in order not to required sudo.
      1. Creation of docker group
         ```
         $ sudo groupadd docker
         ```
      2. Adding a user who want to use docker. In this example, we will add login-user ($USER)
         ```
         $ sudo gpasswd -a $USER docker
         ```
      3. Rebooting PC
         ```
         $ reboot
         ```
    3. Building the Dockerfile
       ```
       $ cd docker
       $ sh docker_build.sh
       ```
### In the case without docker
1. installing mkdocs
   ```
   $ pip install mkdocs
   $ pip install mkdocs-material
   $ pip install mkdocs-awesome-pages-plugin
   ```
2. init mkdocs
   ```
   $ mkdocs new src
   ```
## Development
### documents development cycle
1. Updating the local sstd to the latest one
   ```
   $ make updateLib
   ```
1. Running the local server
   ```
   $ ./make.sh run  # with Docker
   $ make run  # without Docker
   ```
1. Editting documentation under `sstdref/docs_src`
1. Compiling files
   ```
   $ ./make.sh  # with Docker
   $ make -j  # without Docker
   ```
1. Checking the local server (http://localhost:8000/).
1. Adding the changes to git repository.
   ```
   $ git add .
   $ git commit -m 'comments'
   $ git push origin main
   ```
1. Updating the github.io
   ```
   $ ./make.sh updateDocs  # with Docker
   $ make updateDocs # without Docker
   ```
### docker image development cycle
1. Entering the docker container
   ```
   $ docker run --rm -it --name run_sstdref -v $PWD:/home -w /home sstdref_gen:latest sh
   ```
1. Testing the build process in the command line
1. Dropping the build process into the dockerfile

## Release
### Tagging

Tagging rule: sstd-[VersionWrittenBySemanticVersioning]

```bash
git tag -a sstd-X.X.X -m 'sstd-X.X.X' [CommitHash]
git push origin sstd-X.X.X
```

## Command descriptions
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

| File or directory name      | Description Origin |
| --------------------------- | ------------------ |
| docker/                     | Dockerfile and the other required files |
| docs/                       | Static files for github.io |
| docs_src/                   | Markdown files ***for editing*** and generating static site |
| docs_src/docs/custom_dir/   | Custom CSS and JavaScripts |
| mdEx_cpp_example/           | Markdown expansion to run cpp example code by `#mdEx: cpp example (in)` and `#mdEx: cpp example (out)`. `SubStandardLibrary-SSTD--master.zip` under `mdEx_cpp_example/` is used to generate the SSTD execution samples. To update SSTD to the latest version, run `$ make updateLib`. |
| mdEx_title/                 | Markdown extension to automatically generate titles |
| tmp/                        | Temporary files to generate docs/ files and previewing by httpd |
| .git/                       | git files          |
| Makefile                    | `$ make run` for running preview server. `$ make` for rebuild preview. `$ make updateDocs` for build under `src` and update pages on `github.io` |
| README.me                   | This file          |
| make.sh                     | Makefile wrapper for running in Docker |
| template.md                 | Template markdown file for docs_src/ |
| .gitignore                  | Registering files to ignore in order not to track files on git |

## Trouble shooting
### Case1. Unable to find image 'sstdref_gen:latest' locally
You need to build dockerfile using below commands, if docker image is not found when running `$ ./make.sh run`.
```
$ cd docker
$ sh docker_build.sh
```
