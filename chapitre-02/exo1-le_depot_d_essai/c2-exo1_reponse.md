# casse

# on utilise git init pour réinitialiser l'espace 
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier
$ git init
Initialized empty Git repository in C:/Users/joseg/Desktop/Nouveau dossier/.git/

# ensuite Cloning into pour cloner casse dans mon terminal
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier (master)
$ git clone https://github.com/Abouna1Ngah2Stala3Gabyjo/casse.git
Cloning into 'casse'...
remote: Enumerating objects: 3, done.
remote: Counting objects: 100% (3/3), done.
remote: Total 3 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
Receiving objects: 100% (3/3), done.

# ls c'est pour verifier que j'ai un depot vide 
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier (master)
$ ls
casse/

# cd va permettre le déplacement facile d'un fichier a l'autre 
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier (master)
$ cd casse/

# touch nous permet alors d'avoir les trois fichiers en même temps
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ touch file1.txt file2.txt file3.txt

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ ls
README.md  file1.txt  file2.txt  file3.txt

# git status nous montre qu'il y a 3 fichiers dans le depot git
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ git status
On branch main
Your branch is up to date with 'origin/main'.

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        file1.txt
        file2.txt
        file3.txt

nothing added to commit but untracked files present (use "git add" to track)

# ici on ajoute le premier fichier pour le préparer pour le commit
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ git add file1.txt

# premier commit
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ git commit -m "Ajout du premier fichier"
[main 06e5587] Ajout du premier fichier
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 file1.txt

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ git status
On branch main
Your branch is ahead of 'origin/main' by 1 commit.
  (use "git push" to publish your local commits)

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        file2.txt
        file3.txt

nothing added to commit but untracked files present (use "git add" to track)

# ici on ajoute le deuxieme fichier pour le préparer pour le commit
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ git add file2.txt
# deuxieme commit
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ git commit -m "Ajout du deuxieme fichier"
[main f4707a1] Ajout du deuxieme fichier
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 file2.txt

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ git status
On branch main
Your branch is ahead of 'origin/main' by 2 commits.
  (use "git push" to publish your local commits)

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        file3.txt

nothing added to commit but untracked files present (use "git add" to track)

# ici on ajoute le troisieme fichier pour le préparer pour le commit
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ git add file3.txt
# troisième commit
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ git commit -m "ajout du troisieme fichier"
[main b3a8c08] ajout du troisieme fichier
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 file3.txt

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ git status
On branch main
Your branch is ahead of 'origin/main' by 3 commits.
  (use "git push" to publish your local commits)

nothing to commit, working tree clean

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$

# HISTORIQUE EN UNE LIGNE PAR COMMIT
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ git log --oneline
b3a8c08 (HEAD -> main) ajout du troisieme fichier
f4707a1 Ajout du deuxieme fichier
06e5587 Ajout du premier fichier
2dceb8e (origin/main, origin/HEAD) Initial commit


# gaphe 


joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ git log --graph
* commit b3a8c08df258f1f0acaaac03bf69fcb3039d8886 (HEAD -> main)
| Author: Jose Gabi <abounajosephine0@gmail.com>
| Date:   Thu Sep 17 15:34:21 2026 +0100
|
|     ajout du troisieme fichier
|
* commit f4707a16f3fd988cad1dfbfc3a18b0598eeb819d
| Author: Jose Gabi <abounajosephine0@gmail.com>
| Date:   Thu Sep 17 15:31:53 2026 +0100
|
|     Ajout du deuxieme fichier
|
* commit 06e55878647fe7a2df87f270b8142ad917d85210
| Author: Jose Gabi <abounajosephine0@gmail.com>
| Date:   Thu Sep 17 15:31:16 2026 +0100
|
|     Ajout du premier fichier
|
* commit 2dceb8e1198320276c7f1b08901fa467bb452896 (origin/main, origin/HEAD)
  Author: Abouna1Ngah2Stala3Gabyjo <abounajosephine0@gmail.com>
  Date:   Thu Sep 17 15:27:26 2026 +0100

      Initial commit
:
