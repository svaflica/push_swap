if [ -z "$1" ]; then 
	echo "Usage: bash gitcleanpush.sh [your_commit_message]"
	exit 0;
fi

git add .
git rm -r --cached *.dSYM
git rm -r --cached .idea
git rm -r --cached .vscode
git rm -r --cached .DS_Store
git rm -r --cached cmake-build-debug
git rm -r --cached tests
git rm --cached CMakeLists.txt
git rm --cached gitcleanpush.sh
git rm --cached *.o
git rm --cached *.py
git commit -m "$1"
git push
