# Modification de deux choses sans rapport dans le même fichier, puis faire deux commits séparés avec git add -p. puis vérifions dans l'historique que chacun ne contient que son sujet.
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ git switch feature
fatal: invalid reference: feature

# ouverture du fichier 1
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ nano file1.txt

# Modifications
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ git add -p
diff --git a/file1.txt b/file1.txt
index 4aba9ec..f8e7c20 100644
--- a/file1.txt
+++ b/file1.txt
@@ -1 +1,4 @@
+j'aime polytech
+
 premier changement sur la branche mesure-taille.
+j'aime le c++
(1/1) Stage this hunk [y,n,q,a,d,s,e,p,P,?]? s
Split into 2 hunks.
@@ -1 +1,3 @@
+j'aime polytech
+
 premier changement sur la branche mesure-taille.
(1/2) Stage this hunk [y,n,q,a,d,k,K,j,J,g,/,e,p,P,?]? y
@@ -1 +3,2 @@
 premier changement sur la branche mesure-taille.
+j'aime le c++
(2/2) Stage this hunk [y,n,q,a,d,K,J,g,/,e,p,P,?]? n

# premier commit
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ git commit -m "exo4"
[main db7fd11] exo4
 1 file changed, 2 insertions(+)

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ git add -p
diff --git a/file1.txt b/file1.txt
index 492a058..f8e7c20 100644
--- a/file1.txt
+++ b/file1.txt
@@ -1,3 +1,4 @@
 j'aime polytech

 premier changement sur la branche mesure-taille.
+j'aime le c++
(1/1) Stage this hunk [y,n,q,a,d,e,p,P,?]? y

# deuxieme commit
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ git commit -m "ex04"
[main 1fc85c1] ex04
 1 file changed, 1 insertion(+)

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ git status
On branch main
Your branch is ahead of 'origin/main' by 10 commits.
  (use "git push" to publish your local commits)

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        fichier1.txt
        q

nothing added to commit but untracked files present (use "git add" to track)

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ git add -p
No changes.
