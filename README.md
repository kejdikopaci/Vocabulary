## Build and Run

$ make

$ ./vocabulary vocabulary_list_base.txt

## Beschreibung

Das ist ein programm welches Vokabelpaare (ein Wort und dessen Übersetzung in eine andere Sprache) aus einer Datei liest (vocabulary_list_base.txt).
Im Anschluss wird dem Benutzer jeweils ein Element eines Paares ausgegeben und die richtige Übersetzung muss durch den Benutzer eingegeben werden. 
Zum Abschluss wird dem Benutzer angezeigt wie viele richtige Antworten gegeben wurden.

## Programmablauf

Das Programm wird mit einem Kommandozeilenparameter aufgerufen.
Dieser gibt den Dateinamen der zu öffnenden Vokabeldatei an.
Sollte das Programm ohne Kommandozeilenparameter aufgerufen werden kommt es zu einer Fehlermeldung.
Sollte das Programm mit mehr als einem Kommandozeilenparameter aufgerufen werden, so werden alle Parameter nach dem ersten ignoriert.

Im ersten Schritt liest das Programm die Vokabeldatei ein. 
Die Inhalte der Datei werden hierbei am Heap gespeichert werden.

Im zweiten Schritt wird das erste Element des ersten Vokabelpaares gefolgt von der Zeichenfolge " - " ausgegeben und auf eine Benutzereingabe gewartet.

Die vom Benutzer eingegebene Zeichenkette wird mit dem zweiten Element des Vokabelpaares verglichen. 
Stimmen die beiden Zeichenketten überein wird "correct\n" ausgegeben, ansonsten "incorrect\n".

Anschließend wird mit dem nächsten Vokabelpaar fortgesetzt, wobei in diesem Fall das zweite Element ausgegeben wird und die Eingabe mit dem ersten Element verglichen wird.

Für jedes gerade Vokabelpaar (0., 2., 4., ...) wird das erste Element des Paares ausgegeben und die Eingabe mit dem zweiten Element verglichen. 
Für jedes ungerade Vokabelpaar (1., 3., 5., ...) wird das zweite Element des Paares ausgegeben und die Eingabe mit dem ersten verglichen.

Abschließend wird eine Statistik ausgegeben: "[correct] / [pairs]\n" wobei [correct] durch die anzahl der richtig beantworteten Vokabeln und [pairs] durch die Anzahl der Vokabelpaare ersetzt wird.

### Rückgabewerte und Fehlermeldungen

        | Wert | Bedeutung   | Fehlermeldung   |
        | :--: | ----------- | ----------- |
        | 0     | Erfolgsfall | |
[DONE]  | 1    | keine Kommandozeilenparameter   | usage: [executable] filename |
[DONE]  | 2    | Vokabeldatei kann nicht geöffnet werden   | ERROR: cannot open file [filename] |
[DONE]  | 3    | Vokabeldatei ungültig | ERROR: file [filename] invalid |
[DONE]  | 4    | kein Speicher kann mehr angefordert werden | ERROR: Out of Memory |

[executable] wird durch den Namen des kompiliertenProgramms ersetzt.

[filename] wird durch den Namen der Vokabeldatei ersetzt.

