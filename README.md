# Minitalk

L'objectif de ce projet est de coder un "small data exchange program" en utilisant les **UNIX signals**. Il est nécessaire de réaliser deux exécutables : un client et un serveur. Il est nécessaire de faire un **Makefile**. Il est demandé de "handle errors sensitively". 

**Un signal est un message qu'un processus va pouvoir envoyer à un autre. Un signal va notamment permettre de changer le statut d'un processus.** 

À partir du moment où on lance un programme, on va avoir un processus qui va l'encadrer. Par exemple, chaque onglet d'un navigateur est encadré par un processus.

Les signaux permettent de communiquer avec des process. Par exemple, le control C est le "**sigint** signal". Il interrompt le process et lui dit de se stopper. 

**SIGUSR1 et SIGUSR2** sont des process "user defined". Ils vont signifier "ce que nous voulons qu'ils signifient.

Les sigactions seraient préférables aux signals. Rendent le code plus portables.

Le **sigterm signal** indique au process de "terminate itself". Lorsqu'un programme segfault, il envoie un signal SIGfault !

Les signals handlers run asynchronously. C'est notamment pourquoi il est préférable d'utiliser des write plutôt que printf. Certaines fonctions sont **"async signal safe"**.

**kill** porte assez mal son nom, elle possède différentes options. **kill -l** permettre de lister les numéros des signaux que kill peut envoyer. Il peut killer un process mais peut également simplement envoyer un message. Voir **kill -TERM** ou **kill -KILL**. (peut également stop processes, continue processes...)

### Sujet

Le serveur doit être lancé avant le client et doit afficher son **PID.** Le client prend en paramètre le PID et la chaîne de caractères à envoyer. Le client doit communiquer la string passée en paramètre au serveur. Une fois reçue, le serveur doit afficher la chaîne de caractères. 

Le serveur doit afficher le signal très rapidement. Une seconde pour 100 caractères c'est déjà énorme. Le serveur doit pouvoir recevoir des messages de plusieurs clients et ne doit pas avoir besoin d'être restart. Les signaux à utiliser sont **SIGUSR1 et SIGUSR2.**

### Fonctions autorisées

- **signal**
    - signal est une fonction de la librairie standard c. Signal semble être version simplifiée de sigaction / simplified *"software signal facilities".* Signal permet au process de se manipuler lui-même (ou une copie de lui même). Il y a deux types de signaux : ceux qui cause la fin du process et ceux qui ne le font pas. Il y a de nombreux signaux (voir le man)
        - SIGINT interrompt un programme
        - les SIGUSR1 et SIGUSR2 sont les seuls user defined signals.
        - L'argument sig specifie quel signal est reçu. La func procedure permet quant à elle au user de choisir l'action à la réception du signal. L'action default est SIG_DFL.

    ```c
    /* Cette fonction pourrait permettre de modifier le comportement du control c */
    signal(SIGINT, fonction);
    /* La fonction getpid() permettra au serveur / process d'afficher son id */
    getpid();

    /* On doit faire une instruction pour les différents types de signaux et la fonction à la réception de celui-ci */
    ```

- **sigemptyset**
    - Cette fonction manipule un "signal set", stockée dans un sigset_t. sigemptysed doit être appelée pour chaque objet de type sigset_t avant tout autre utilisation de l'objet.
- **sigaddset**
    - sigaddset ajoute le "signo" au "signal set".
- **sigaction**
    - Une sigaction est une structure (un peu particulière) ? Wikipedia : C'est une API function définie par POSIX "to give the programmer access to what should be a program's behaviour when receiving a specific OS signal.
- **kill**
    - L'utilitaire "kill" envoie un signal aux processus spécifiés par le pid "operand". Seulement le super-user peut envoyer des signaux à d'autres processus. Pour pouvoir effectuer un kill il faut en premier lieux avoir récupérer le pid ;).
- **getpid**
    - unistd.h → returns the process ID of the calling process of the calling process. Id garanteed to be unique.
- **pause**
    - pause is made obsolete by sigsuspend. La fonction pause cause la pause du processus jusqu'a ce que soit un kill ou une autre fonction.
- **sleep**
    - suspend l'exécution pour un intervalle de temps
- **usleep**
    - suspend l'exécutiion d'un threard à un intervalle de temps mesuré en microsecondes
- **exit**
    - man 3 exit : termine un processus.

## BONUS

- Ajouter un "small acknowledgement system".
- Supporter les Unicode characters.

## Traduction d'un message binaire

Pour rappel, 8 bits (1 octet) permettent de représenter un char.

## Bit shifting and bit masking

[https://www.youtube.com/watch?v=meGcdIoTYgw](https://www.youtube.com/watch?v=meGcdIoTYgw)