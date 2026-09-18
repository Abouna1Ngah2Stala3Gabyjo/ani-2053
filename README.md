# MODIFICATION DU FICHIER1 (file1.txt)

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ cat file1.txt

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ nano file1.txt

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ cat file1.txt
Ici c'est mon premier fichier git.
# git status 
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ git status
On branch main
Your branch is ahead of 'origin/main' by 3 commits.
  (use "git push" to publish your local commits)

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   file1.txt

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        q

no changes added to commit (use "git add" and/or "git commit -a")

# git add file1.txt
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ git add file1.txt
warning: in the working copy of 'file1.txt', LF will be replaced by CRLF the next time Git touches it
#git status
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ git status
On branch main
Your branch is ahead of 'origin/main' by 3 commits.
  (use "git push" to publish your local commits)

Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   file1.txt

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        q

# git commit -m "modification du premier fichier"
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ git commit -m "modification du premier fichier"
[main 4c24c90] modification du premier fichier
 1 file changed, 1 insertion(+)
#git status
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ git status
On branch main
Your branch is ahead of 'origin/main' by 4 commits.
  (use "git push" to publish your local commits)

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        q

nothing added to commit but untracked files present (use "git add" to track)

# Qu'est ce qui change entre elles 

le premier status nous montre que le premier fichier a ete modifier
le deuxime, les modifications ont ete faites sans etre envoye dans le depot
