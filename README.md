# L3_ISEI_S5-Reseau_de_capteurs

## Installation
1. Installer ns3.32 en suivant ce tuto : 
2. Copier les fichiers de ce dépôt dans *./ns-alinone-3.32/ns-3.32/src/netanim/examples*
3. Dans le fichier wscript (dans le même dossier qu'au point 2.), ajouter les lignes suivantes :
```py   
obj = bld.create_ns3_program('mini-projet',
                                 ['netanim', 'applications'])
    obj.source = 'mini-projet.cc'
```
   
5. Pour compiler le tout : <br>
Depuis *./ns-alinone-3.32/ns-3.32*, tapez la commande suivante :
```./waf build```
