# Minishell

## Description des fonctions
- `readline` : Une fonction qui permet de prendre un entrE dans le terminal.
	> [!IMPORTANT]
	> Cette fonction presente des memoires qui ne sont pas liberE (qui present des erreurs de still reachable)
	
	> [!NOTE]
	> Les fonctions 'rl_*' sont des fonctions liEes a la fonction readline sur la gestion de l'historique
	
	```
	extern char *readline PARAMS((const char *));
	```
- `access` : 
