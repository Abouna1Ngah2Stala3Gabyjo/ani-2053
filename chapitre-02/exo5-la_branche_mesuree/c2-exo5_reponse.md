# creation d'une branche, faire trois commits dessus, et mesurer la place que le dépôt a gagnée sur le disque. 

# Mesurer la taille du depot avant les trois commits
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ du -sh .git
115K    .git

# creation de la nouvelle branche branche
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (main)
$ git switch -c taille-progresse
Switched to a new branch 'taille-progresse'

# verification de la branche
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (taille-progresse)
$ git branch
  main
* taille-progresse


# Premier commit
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (taille-progresse)
$ echo "Premier changement sur la branche taille-progresse." > file1.txt

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (taille-progresse)
$ git status
On branch taille-progresse
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   file1.txt

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        fichier1.txt
        q

no changes added to commit (use "git add" and/or "git commit -a")

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (taille-progresse)
$ git add file1.txt
warning: in the working copy of 'file1.txt', LF will be replaced by CRLF the next time Git touches it

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (taille-progresse)
$ git status
On branch taille-progresse
Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   file1.txt

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        fichier1.txt
        q


joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (taille-progresse)
$ git commit -m "premier fichier"
[taille-progresse e9fe2e2] premier fichier
 1 file changed, 1 insertion(+), 1 deletion(-)


# Deuxieme commit
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (taille-progresse)
$ echo "Deuxieme changement sur la branche taille-progresse." > file2.txt

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (taille-progresse)
$ git status
On branch taille-progresse
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   file2.txt

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        fichier1.txt
        q

no changes added to commit (use "git add" and/or "git commit -a")

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (taille-progresse)
$ git add file2.txt
warning: in the working copy of 'file2.txt', LF will be replaced by CRLF the next time Git touches it

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (taille-progresse)
$ git commit -m
error: switch `m' requires a value

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (taille-progresse)
$ git commit -m "deuxieme fichier"
[taille-progresse a740ece] deuxieme fichier
 1 file changed, 1 insertion(+), 1 deletion(-)


# Troisieme commit
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (taille-progresse)
$ echo "troisieme changement sur la branche taille-progresse." > file3.txt

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (taille-progresse)
$ git status
On branch taille-progresse
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   file3.txt

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        fichier1.txt
        q

no changes added to commit (use "git add" and/or "git commit -a")

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (taille-progresse)
$ git add file3.txt
warning: in the working copy of 'file3.txt', LF will be replaced by CRLF the next time Git touches it

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (taille-progresse)
$ git commit -m"troisieme fichier"
[taille-progresse 15a5b82] troisieme fichier
 1 file changed, 1 insertion(+), 1 deletion(-)

# Verification des commits
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (taille-progresse)
$ git log --oneline
15a5b82 (HEAD -> taille-progresse) troisieme fichier
a740ece deuxieme fichier
e9fe2e2 premier fichier
5bcdb84 (main) Ajout du troisieme fichier
5fc1dc8 Ajout du deuxieme fichier
6f0b46d Ajout du premier fichier
e86b832 Ajout du prmier fichier
4c24c90 Ajout du premier fichier
b3a8c08 ajout du troisieme fichier
f4707a1 Ajout du deuxieme fichier
06e5587 Ajout du premier fichier
2dceb8e (origin/main, origin/HEAD) Initial commit

# Verification de la branche
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (taille-progresse)
$ git branch
  main
* taille-progresse

# Mesure de la taille du depot apres les commits
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (taille-progresse)
$ du -sh .git
129K    .git

# Graphe
joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (taille-progresse)
$ git log --oneline --graph --all
* 15a5b82 (HEAD -> taille-progresse) troisieme fichier
* a740ece deuxieme fichier
* e9fe2e2 premier fichier
* 5bcdb84 (main) Ajout du troisieme fichier
* 5fc1dc8 Ajout du deuxieme fichier
* 6f0b46d Ajout du premier fichier
* e86b832 Ajout du prmier fichier
* 4c24c90 Ajout du premier fichier
* b3a8c08 ajout du troisieme fichier
* f4707a1 Ajout du deuxieme fichier
* 06e5587 Ajout du premier fichier
* 2dceb8e (origin/main, origin/HEAD) Initial commit

joseg@DESKTOP-Q0F6L6Q MINGW64 ~/Desktop/Nouveau dossier/casse (taille-progresse)
$ git status
On branch taille-progresse
Untracked files:
  (use "git add <file>..." to include in what will be committed)
        fichier1.txt
        q

nothing added to commit but untracked files present (use "git add" to track)

# LA PLACE QUE LE DEPOT A GAGNEE SUR LE DISQUE

Avant : 115ko
Apres : 129ko
la difference est :
129 - 115 = 14ko

La taille du dépôt augmente après les commits car Git doit enregistrer dans le dossier, commits, arbres et contenus des fichiers. L'augmentation observée dépend donc principalement des données ajoutées ou modifiées lors des trois commits. Git ne recopie pas nécessairement intégralement tous les fichiers à chaque commit et il peut aussi réutiliser les données déjà présentes. 
