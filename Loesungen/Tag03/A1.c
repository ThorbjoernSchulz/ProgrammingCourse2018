// Bzgl. ggt siehe Lösungen von gestern!

// Reduziert x auf sein Vorzeichen.
// Gibt 1 zurück wenn x positiv ist, -1 wenn es negativ ist und 0 sonst
int sgn(int x) {
  if (x < 0) { 
    return -1;
  }

  // hier nutzen wir aus, dass 'false' in C zu 0 evaluliert,
  // und 'true' zu 1
  return x > 0;
}

// Gibt den Betrag von x zurück.
// Anmerkung: Rückgabetyp unsigned wäre auch in Ordnung.
// Diskussion dazu unten, wen das interessiert.
int betrag(int x) {
  if (x < 0) {
    return x * -1;
  }

  return x;
}

// So, also warum int betrag(int x) statt unsigned betrag(int x).
// Nehmen wir mal an, unser integer wäre 4 Byte groß. Das ist so der Regelfall.
// Dann können wir damit Zahlen von -(2^31) bis 2^31 - 1 darstellen.
// Jetzt kann man sagen: Hey, d.h. wenn wir in unsere Betragfunktion -(2^31)
// rein packen, dann bekommen wir ja ein falsches Ergebniss.
int printf(const char *, ...);
int main(void) { 
  printf("%d\n", betrag(-2147483647));
  printf("%d\n", betrag(-2147483648));
  return 0;
}
// Und das schlimme ist: Der Compiler merkt das nicht einmal.
// Wenn Sie das hier kompilieren, dann gibt es keine Warnung!
// Und ja: Wer sagt das ist schrecklich, der hat vollkommen recht.
// Mit einem unsigned als Rückgabewert hätten wir das Problem nicht.
// Denn ein 4-byte unsigned int kann Zahlen von 0 bis 2^32 - 1 darstellen, und
// der komplette Wertebereich wäre abgedeckt.
//
// Aber ganz ehrlich: Wenn wir uns in diesen höhen bewegen, dann wäre es schon 
// sehr fahrlässig so eine Funktion zu verwenden. Dann hätten wir auch gleich
// long betrag(long) wählen können.
//
// Es ist einfach simpler so. Und simpler ist immer besser.
// Und tendenziell passieren mehr Fehler mit unsigned. Versuchen Sie sich
// keinen Kopf darüber zu machen, außer es ist notwendig. Der default sollte
// einfach int sein, wenn es um Ganzzahlen geht. Wenn sie etwas anderes 
// brauchen, merken sie das schon.

