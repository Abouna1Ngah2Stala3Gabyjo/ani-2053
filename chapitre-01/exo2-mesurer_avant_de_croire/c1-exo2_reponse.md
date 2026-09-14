# le nombre de fichier source est de 4796

# le chapitre indique 2 638

# le nombre de ligne de depot est de 2600167
comme :PS C:\Users\Asus\OneDrive\Desktop\code\Nkentseu> (Get-childItem -Recurse -Include*.cpp, *.c, *.hpp, *h -file| Get-content | Measure-Object-Line).Lines 2600167
# le chapitre indique 1 193 385

la difference est au niveau du nombre de fichiers et de lignes plus eleves dans la vestion de depot actuelle que dans la lecon.
