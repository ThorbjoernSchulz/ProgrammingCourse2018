#pragma once
/*
 * Queue:
 * Hinweis: Kompilieren Sie Ihre Programme stehts mit -fsanitize=address,leak
 *
 * 1)
 * Definieren Sie die hier aufgeführten Deklarationen mit Hilfe der gebenen
 * Listenimplementierung, sodass der Test in test_queue.c erfolgreich
 * durchläuft.
 *
 * 2)
 * Erstellen Sie eine neue .c Datei queue_feld.c und benutzen Sie die selben
 * Deklarationen für die Implementierung einer Queue auf Basis eines
 * dynamischen Arrays. Kompilieren Sie am Ende queue_feld.c statt queue.c und
 * linken Sie die neue Implementation gegen den Test.
 *
 * 3)
 * Angenommen die maximal nötige Größe der Queue stünde bereits fest. Wie
 * könnte eine Implementierung auf einem Feld aussehen, bei der nur ein
 * einziges mal Speicher allokiert wird? Überlegen Sie sich zunächst ein
 * Konzept.
 */

struct IntQueue;
typedef struct IntQueue IntQueue;

IntQueue *IntQueue_new(void);
int IntQueue_enqueue(IntQueue *queue, int value);
int IntQueue_dequeue(IntQueue *queue);
void IntQueue_delete(IntQueue *queue);
int IntQueue_empty(IntQueue *queue);
