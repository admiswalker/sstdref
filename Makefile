run:
	@(xdg-open http://127.0.0.1:8000/)
	@(cd ./src; mkdocs serve)

build:
	@(cd ./src; mkdocs build)
	@(mkdir -p ./docs)
	@(cp -r ./src/site/* ./docs)

updateDocs:
	@(make build)
	@(git add ./docs)
	@(git commit -m 'Update docs')
	@(git push origin main)


clean:
	@(rm -rf ./docs)
