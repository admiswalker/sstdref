#!/bin/bash

showHelp(){
    echo "Usages:"
    echo "  $ $0            : Building the documents"
    echo "  $ $0 clean      : Removing the temporary files"
    echo "  $ $0 help       : Showing the help (This messages)"
    echo "  $ $0 run        : Running the previewing server on a local machine"
    echo "  $ $0 genDocs    : Generating the documents in local ./docs"
    echo "  $ $0 upDocs     : Uploading the documents in local ./docs to the github repository"
    echo "  $ $0 updateDocs : Updating the documents on github.io (same as a '$ make genDocs; make upDocs')"
}

if [ $# -gt 1 ]; then
    showHelp
    exit 1
fi

dRun="docker run --rm -u $(id -u $USER) -it -w /home"
opt1="--name run_sstdref_build -v $PWD:/home"
opt2="--name run_sstdref_httpd -v $PWD/tmp/site:/home -p 8000:8000"
dImg="sstdref_gen:latest"

case "$1" in
    ""           ) eval "$dRun $opt1 $dImg make -j";;
    "clean"      ) eval "$dRun $opt1 $dImg make clean";;
    "run"        ) eval "$dRun $opt1 $dImg make -j"; xdg-open http://localhost:8000/; eval "$dRun $opt2 $dImg python -m http.server 8000";;
    "genDocs"    ) eval "$dRun $opt1 $dImg make genDocs";;
    "upDocs"     ) eval make upDocs ;;
    "updateDocs" ) eval "$dRun $opt1 $dImg make genDocs"; make upDocs ;;
    "help"       ) showHelp; exit 1;;
    *            ) showHelp; exit 1;;
esac
