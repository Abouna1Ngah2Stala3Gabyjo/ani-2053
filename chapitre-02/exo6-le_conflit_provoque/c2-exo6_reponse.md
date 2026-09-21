# Depuis deux répertoires de travail, ou deux clones, modifions la même ligne d'un même fichier et poussons l'un des deux. Provoquons le refus, puis le conflit, puis résolvons-le. Rendre chaque message affiché.

# Creation du premier depot
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ mkdir exercice-conflit

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ cd exercice-conflit

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse/exercice-conflit (main)
$ git init
Initialized empty Git repository in C:/Users/joseg/Desktop/Nouveau dossier/casse/exercice-conflit/.git/

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse/exercice-conflit (master)
$ git status
On branch master

No commits yet

nothing to commit (create/copy files and use "git add" to track)

# Creation du premier fichier
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse/exercice-conflit (master)
$ pwd
/c/Users/joseg/Desktop/Nouveau dossier/casse/exercice-conflit

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse/exercice-conflit (master)
$ touch fille1.txt

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse/exercice-conflit (master)
$ ls
fille1.txt

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse/exercice-conflit (master)
$ echo "BONJOUR" > fille1.txt

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse/exercice-conflit (master)
$ cat fille1.txt
BONJOUR

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse/exercice-conflit (master)
$ it add fille1.txt
bash: it: command not found

# Le commit
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse/exercice-conflit (master)
$ git commit -m "Creation de fille1.txt"
On branch master

Initial commit

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        fille1.txt

nothing added to commit but untracked files present (use "git add" to track)

# Relier le depot a Github
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse/exercice-conflit (master)
$ git remote add origin https://github.com/Abouna1Ngah2Stala3Gabyjo/nom-du-depot.git

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse/exercice-conflit (master)
$ git remote -v
origin  https://github.com/Abouna1Ngah2Stala3Gabyjo/nom-du-depot.git (fetch)
origin  https://github.com/Abouna1Ngah2Stala3Gabyjo/nom-du-depot.git (push)


# Premier push
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse/exercice-conflit (master)
$ git push -u
fatal: The current branch master has no upstream branch.
To push the current branch and set the remote as upstream, use

    git push --set-upstream origin master

To have this happen automatically for branches without a tracking
upstream, see 'push.autoSetupRemote' in 'git help config'.


joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse/exercice-conflit (master)
$ git push -u origin master
error: src refspec master does not match any
error: failed to push some refs to 'https://github.com/Abouna1Ngah2Stala3Gabyjo/nom-du-depot.git'

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse/exercice-conflit (master)
$ git push -u
fatal: The current branch master has no upstream branch.
To push the current branch and set the remote as upstream, use

    git push --set-upstream origin master

To have this happen automatically for branches without a tracking
upstream, see 'push.autoSetupRemote' in 'git help config'.


# deuxieme clone
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse/exercice-conflit (master)
$ cd ..

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ git clone https://github.com/Abouna1Ngah2Stala3Gabyjo/nom-du-depot-B
Cloning into 'nom-du-depot-B'...
fatal: unable to access 'https://github.com/Abouna1Ngah2Stala3Gabyjo/nom-du-depot-B/': Could not resolve host: github.com

# verification du dossier B
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ cd depot-B
bash: cd: depot-B: No such file or directory

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ git status
On branch main
Your branch is ahead of 'origin/main' by 10 commits.
  (use "git push" to publish your local commits)

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        exercice-conflit/
        fichier1.txt
        q

nothing added to commit but untracked files present (use "git add" to track)

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ cd ../exercice-conflit
bash: cd: ../exercice-conflit: No such file or directory

# modification du depot A
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ nano fille1.txt

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ ls
README.md  exercice-conflit/  fichier1.txt  file1.txt  file2.txt  file3.txt  q

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ touch file2.txt

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ ls
README.md  exercice-conflit/  fichier1.txt  file1.txt  file2.txt  file3.txt  q

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ add file2.txt
bash: add: command not found

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ echo "bonsoir" > file2.txt

# le commit
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ git commit -m "creation du fichier"
On branch main
Your branch is ahead of 'origin/main' by 10 commits.
  (use "git push" to publish your local commits)

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   file2.txt

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        exercice-conflit/
        fichier1.txt
        q

no changes added to commit (use "git add" and/or "git commit -a")

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ git remote -v
origin  https://github.com/Abouna1Ngah2Stala3Gabyjo/casse.git (fetch)
origin  https://github.com/Abouna1Ngah2Stala3Gabyjo/casse.git (push)

# Le deuxieme push
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ git push -u
To https://github.com/Abouna1Ngah2Stala3Gabyjo/casse.git
 ! [rejected]        main -> main (fetch first)
error: failed to push some refs to 'https://github.com/Abouna1Ngah2Stala3Gabyjo/casse.git'
hint: Updates were rejected because the remote contains work that you do not
hint: have locally. This is usually caused by another repository pushing to
hint: the same ref. If you want to integrate the remote changes, use
hint: 'git pull' before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ cd ..

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier (master)
$ \q
bash: q: command not found

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier (master)
$ cd ..

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop
$ git clone https://github.com/Abouna1Ngah2Stala3Gabyjo/nom-du-depot.git depot-B
Cloning into 'depot-B'...
remote: Repository not found.
fatal: repository 'https://github.com/Abouna1Ngah2Stala3Gabyjo/nom-du-depot.git/' not found

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop
$ cd depot-B
bash: cd: depot-B: No such file or directory

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop
$ git status
fatal: not a git repository (or any of the parent directories): .git

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop
$ git init
Initialized empty Git repository in C:/Users/joseg/Desktop/.git/

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop (master)
$ mkdir exercice-conflit

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop (master)
$ cd exercice-conflit

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/exercice-conflit (master)
$ gir init
bash: gir: command not found

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/exercice-conflit (master)
$ git status
On branch master

No commits yet

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        ../.vscode/
        ../Ani-2053/

nothing added to commit but untracked files present (use "git add" to track)
