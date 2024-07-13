<h1 align="center">Peer To Pay</h1>
<div align="center">
  <img src="https://i.ibb.co/kqQ1sHV/Registrazione-applicativo-programmazione.gif" alt="Registrazione-applicativo-programmazione" border="0">
  <br>
  <br>
  <i>Peer To Pay è un'applicazione che ha come obiettivo principale quello di monitorare le transazioni tra utenti registrati.</i>
  <br>
</div>

## Strumenti Utilizzati

<p align='left'>
  Questo applicativo è stato realizzato utilizzando la libreria grafica <b>WxWidgets</b> e un database <b>MySql</b>.<br>
  Le classi principali sono state testate utilizzando <b>GoogleTest</b> mentre per la cattura di eventuali memory leak è stato utilizzato lo strumento <b>CppCheck</b>.
</p>

## Funzionalità Principali

### Registrazione:

<p align='left'>
  Permette la creazione di un account, l'email è univoca per ogni account, la password viene cifrata prima di essere salvata nel database.
</p>

### Accesso:

<p align='left'>
  Oltre a consentire la verifica delle credenziali permette di salvare le credenziali in locale nel file <b>credenziali.txt</b> (se la verifica ha avuto esito positivo), i campi email e password verranno compilati automaticamente alla successiva esecuzione del programma.
</p>

### Home:

<p align='left'>
  Consente la visualizzazione del saldo attuale sul conto associato (se presente), permette di visualizzare/esportare i movimenti relativi all'utente, l'esportazione produrrà un file di testo con una transazione per riga.
</p>

### Invia:

<p align='left'>
  Inserendo il codice (valido) fornito da un altro utente sarà possibile inviare una somma pari o inferiore alla disponibilità economica presente sul proprio conto.
</p>

### Ricevi:

<p align='left'>
  Verrà generato automaticamente un codice numerico di 5 cifre (univoco) per identificare quell'utente all'interno della piattaforma, il codice avrà una durata di 15 minuti, è possibile generarne di nuovi.
</p>

### Conto:

<p align='left'>
  Permette l'inserimento dei parametri di una carta di credito (Numero di conto, scadenza, cvv) ed il valore in euro disponibile, possiamo modificarne i parametri all'occorrenza.
</p>

### Logout:

<p align='left'>
  L'utente verrà disconnesso e riportato alla pagina di accesso.
</p>
