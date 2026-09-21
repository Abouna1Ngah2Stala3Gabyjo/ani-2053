# Deux personnes modifient le même fichier, mais à deux endroits éloignés. Montrez que git assemble les deux sans rien demander.

# verifions d'abord l'emplacement
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop (master)
$ cd /c/Users/joseg/Desktop

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop (master)
$ pwd
/c/Users/joseg/Desktop

# Creation du dossier pour l'exercice
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop (master)
$ mkdir exercice-fusion-auto

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop (master)
$ cd exercice-fusion-auto

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/exercice-fusion-auto (master)
$ pwd
/c/Users/joseg/Desktop/exercice-fusion-auto

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/exercice-fusion-auto (master)
$ git init
Initialized empty Git repository in C:/Users/joseg/Desktop/exercice-fusion-auto/.git/

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/exercice-fusion-auto (master)
$ git status
On branch master

No commits yet

nothing to commit (create/copy files and use "git add" to track)

# Creation du fichier nano et enregistrer le fichier
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/exercice-fusion-auto (master)
$ nano file3.txt

# verifions le fichier
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/exercice-fusion-auto (master)
$ ls
file3.txt

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/exercice-fusion-auto (master)
$ cat fichier.txt
cat: fichier.txt: No such file or directory

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/exercice-fusion-auto (master)
$ cat file3.txt
Ligne 1 : Bonjour
Ligne 2 : Je suis etudiante.
Ligne 3 : J'apprends Git.
Ligne 4 : Git est interessant.
Ligne 5 : fin du fichier.

# Le premier commit
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/exercice-fusion-auto (master)
$ git commit -m "Creation du fichier"
On branch master

Initial commit

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        file3.txt

nothing added to commit but untracked files present (use "git add" to track)

# Simulation de deux personnes et creation de la branche de la personne A
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/exercice-fusion-auto (master)
$ git switch -c personne-A
Switched to a new branch 'personne-A'

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/exercice-fusion-auto (personne-A)
$ git branch

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/exercice-fusion-auto (personne-A)
$ nano file3.txt

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/exercice-fusion-auto (personne-A)
$ git commit -m "Modification du debut par A"
[personne-A (root-commit) 30ec362] Modification du debut par A
 1 file changed, 5 insertions(+)
 create mode 100644 file3.txt

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/exercice-fusion-auto (personne-A)
$ git switch main
fatal: invalid reference: main

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/exercice-fusion-auto (personne-A)
$ git branch
* personne-A

# Personne A modifie le debut du fichier
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/exercice-fusion-auto (personne-A)
$ nano file3.txt

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/exercice-fusion-auto (personne-A)
$ git diff
warning: in the working copy of 'file3.txt', LF will be replaced by CRLF the next time Git touches it
diff --git a/file3.txt b/file3.txt
index 9b72a37..7c67d5e 100644
--- a/file3.txt
+++ b/file3.txt
@@ -1,4 +1,4 @@
-Ligne 1 : Bonjour depuis la personne A
+Ligne 1 : Bonjour depuis personnage A
 Ligne 2 : Je suis etudiante.
 Ligne 3 : J'apprends Git.
 Ligne 4 : Git est interessant.

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/exercice-fusion-auto (personne-A)
$ git add file3.txt
warning: in the working copy of 'file3.txt', LF will be replaced by CRLF the next time Git touches it

# Commit de A
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/exercice-fusion-auto (personne-A)
$ git commit -m "Modiffication du debut par personnage A"
[personne-A 5808421] Modiffication du debut par personnage A
 1 file changed, 1 insertion(+), 1 deletion(-)

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/exercice-fusion-auto (personne-A)
$ git switch main
fatal: invalid reference: main

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/exercice-fusion-auto (personne-A)
$ git branch
* personne-A

# Création la branche de la personne B
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/exercice-fusion-auto (personne-A)
$ git switch -c personne-B
Switched to a new branch 'personne-B'

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/exercice-fusion-auto (personne-B)
$ git branch
  personne-A
* personne-B

# Personne B modifie une autre partie du même fichier
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/exercice-fusion-auto (personne-B)
$ nano file3.txt

# verifions la modification de B
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/exercice-fusion-auto (personne-B)
$ git diff
warning: in the working copy of 'file3.txt', LF will be replaced by CRLF the next time Git touches it
diff --git a/file3.txt b/file3.txt
index 7c67d5e..82296d8 100644
--- a/file3.txt
+++ b/file3.txt
@@ -2,4 +2,4 @@ Ligne 1 : Bonjour depuis personnage A
 Ligne 2 : Je suis etudiante.
 Ligne 3 : J'apprends Git.
 Ligne 4 : Git est interessant.
-Ligne 5 : fin du fichier.
+Ligne 5 : fin du fichier - modifie par B.

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/exercice-fusion-auto (personne-B)
$ git add file3.txt
warning: in the working copy of 'file3.txt', LF will be replaced by CRLF the next time Git touches it

# Commit de B
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/exercice-fusion-auto (personne-B)
$ git commit -m "Modification de la fin par B"
[personne-B 90c4a0f] Modification de la fin par B
 1 file changed, 1 insertion(+), 1 deletion(-)

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/exercice-fusion-auto (personne-B)
$ git branch
  personne-A
* personne-B

# Fusionner la branche A dans B
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/exercice-fusion-auto (personne-B)
$ git merge personne-A
Already up to date.

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/exercice-fusion-auto (personne-B)
$ git merge personne-A
Already up to date.

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/exercice-fusion-auto (personne-B)
$ cat file3.txt
Ligne 1 : Bonjour depuis personnage A
Ligne 2 : Je suis etudiante.
Ligne 3 : J'apprends Git.
Ligne 4 : Git est interessant.
Ligne 5 : fin du fichier - modifie par B.

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/exercice-fusion-auto (personne-B)
$ git status
On branch personne-B
nothing to commit, working tree clean
