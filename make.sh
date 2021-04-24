#!/bin/bash

showHelp(){
    echo "Usages:"
    echo "  $ $0"
    echo "  $ $0 clean"
    echo "  $ $0 help"
    echo "  $ $0 run"
    echo "  $ $0 updateDocs"
}

if [ $# -gt 1 ]; then
    showHelp
    exit 1
fi

dRun="docker run --rm -it --name run_sstdref -w /home"
opt1="-v $PWD:/home"
opt2="-v $PWD/docs:/home -p 8000:8000"
dImg="sstdref_gen:latest"

case "$1" in
    ""           ) eval "$dRun $opt1 $dImg make -j";;
    "clean"      ) eval "$dRun $opt1 $dImg make clean";;
    "run"        ) eval "$dRun $opt1 $dImg make -j"; xdg-open http://localhost:8000/; eval "$dRun $opt2 $dImg python -m http.server 8000";;
    "updateDocs" ) eval "$dRun $opt1 $dImg make updateDocs";;
    "help"       ) showHelp; exit 1;;
    *            ) showHelp; exit 1;;
esac
