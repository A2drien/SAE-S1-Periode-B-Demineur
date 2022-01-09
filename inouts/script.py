import os

commande = ""                   # Variable contenant la commande de sortie

nomExe = "Demineur.exe"

cheminRun = ""                  # Chemin relatif des fichiers run
cheminIn = ""                   # Chemin relatif des fichiers in
cheminOut = ""                  # Chemin relatif des fichiers out

sprintMin = 2                   # Commence au Sprint n
sprintMax = 4                   # Termine par le Sprint n

liste = ["a", "b", "c"]

utiliserFichiersProfs = True    # Utiliser les fichiers frauduleux (G07, G08, G09) ?
utiliserFichiersBase = True     # Utiliser les fichiers fournis par défaut ?

cheminBat = 'SAE-1-02-Demineur\\inout\\'

for i in range(sprintMin, sprintMax+1):
    if utiliserFichiersProfs:
        for uio in range(3):
            j = liste[uio]
            commande += f'{nomExe} <"{cheminIn}in{i}{j}.txt"> "{cheminRun}run{i}{j}.txt" & fc.exe "{cheminOut}out{i}{j}.txt" "{cheminRun}run{i}{j}.txt" & '
    
    #if utiliserFichiersBase:
        #commande += f'{nomExe} <"{cheminIn}in{j}.txt"> "{cheminRun}run{j}.txt" & fc.exe "{cheminOut}out{j}.txt" "{cheminRun}run{j}.txt" & '

print(commande[:-3])

file = open(cheminBat+"listeCommande.bat", "w")
file.write(commande[:-3]+"\nPAUSE")
file.close()