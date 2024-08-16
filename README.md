# Minishell

## Description des fonctions
- `readline` : Fonction qui permet de prendre un entrE dans le terminal.
	```
	PROTOTYPE :	extern char *readline PARAMS((const char *));
	```

	> [!IMPORTANT]
	> Cette fonction presente des memoires qui ne sont pas liberE (qui present des erreurs de still reachable)
	
	> [!NOTE]
	> Les fonctions 'rl_*' sont des fonctions liEes a la fonction readline sur la gestion de l'historique
	

- `access` : Fonction qui vErifie si un fichier ou un dossier est accEssible
	```
	PROTOTYPE	: int access(const char * path, int amode);
	RETURN		: 0 si oui, sinon -1
	```
	__amode__:
	1. `F_OK` : test d'existance d'un fichier
	2. `R_OK` : test de permission de lecture d'un fichier
	3. `W_OK` : test de permission d'ecriture d'un fichier
	4. `X_OK` : test de permission d'execution d'un fichier, pour un dossier c'est pour la permission de recherche


- `getcwd` : Fonction qui permet de rEcupErer le rEpertoire de travail courant
	```
	PROTOTYPE	: char* getcwd(char* buffer, size_t size);
	```

- `chdir` : Fonction qui permet de changer de repertoire
	```
	PROTOTYPE	: int chdir(const char * path);
	RETURN		: 0 si oui, sinon -1
	```

- `stat` : Fonction qui permet de rEcuperer les informations concernant un fichier
	```
	PROTOTYPE	: int stat(const char *restrict path, struct stat *restrict buf);
	RETURN		: 0 si tout c'est bien passE, sinon -1
	```

- `fstat` : Fonction qui permet de rEcuperer les informations concerant un fichier ouvert
	```
	PROTOTYPE	: int fstat(int fildes, struct stat *buf);
	RETURN		: 0 si tout c'est bien passE, sinon -1
	```
	> [!NOTE]
	> fildes : file descriptor

- `unlink` : Détruit un nom dans le système de fichiers. Si ce nom était le dernier lien sur un fichier, et si aucun processus n'a ouvert ce fichier, ce dernier est effacé, et l'espace qu'il utilisait est rendu disponible.
Si le nom était le dernier lien sur un fichier, mais qu'un processus conserve encore le fichier ouvert, celui-ci continue d'exister jusqu'à ce que le dernier descripteur le référençant soit fermé.
Si le nom correspond à un lien symbolique, le lien est supprimé.
	```
	PROTOTYPE	: int unlink(const char *pathname);
	RETUR		: 0 si tout c'est bien passE, sinon -1
	```

- `execve` : Pour que ce soit plus claire concernant cette fonction, voici un lien youtube qui l'explique en mieux :
(https://www.youtube.com/watch?v=OVFEWSP7n8c&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=13)

## Utilisation du Makefile

- `leaks`	: Une regle qui permet de faire un valgrind sur l'executable avec des suppressions. Le fichier de suppression se trouve dans `src/suppressed.supp`.
	```
	EXECUTION	:
		$ make leaks <L_ARGS=[minishell_args]>

		<L_ARGS> : argument optionnel
	```

- `suppr`	: Une regle qui permet de generer les suppressions a definir dans `src/suppressed.supp`.
	```
	EXECUTION	:
		$ make suppr
	```

	> [!NOTE]
	> Il faut taper `y` ou `Y` quand `valgrind` demande l'affichage des suppressions a considerer.
