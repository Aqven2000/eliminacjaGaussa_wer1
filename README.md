# Format wejścia plików i sposób działania

Ten dokument wyjaśnia format wejścia plików oraz sposób, w jaki program przetwarza dane macierzy z plików.

## Wymagania dotyczące plików wejściowych

### **Format pliku wejściowego macierzy**
Każdy plik wejściowy macierzy powinien mieć następującą strukturę:

1. **Pierwsza linia:** Zawiera dwie liczby całkowite określające liczbę wierszy (`r`) i kolumn (`c`) macierzy.
   ```
   r c
   ```

2. **Kolejne linie:** Zawierają elementy macierzy, wiersz po wierszu, z każdym elementem oddzielonym spacją.
   ```
   a11 a12 a13 ... a1c
   a21 a22 a23 ... a2c
   ...
   ar1 ar2 ar3 ... arc
   ```

### **Format pliku wektora wyników**
Jeśli wektor wyników jest przechowywany w osobnym pliku, powinien mieć podobny format:

1. **Pierwsza linia:** Zawiera dwie liczby całkowite: liczbę wierszy (`r`) i liczbę kolumn (`1`).
   ```
   r 1
   ```

2. **Kolejne linie:** Zawierają elementy wektora, po jednym w każdym wierszu.
   ```
   b1
   b2
   b3
   ...
   br
   ```

---

## Jak program przetwarza pliki

### **Funkcja: `initMatrixFromFile`**
Ta funkcja odpowiada za wczytywanie danych macierzy z pliku.

#### **Kroki:**
1. **Otwieranie pliku:**
   - Program otwiera plik na podstawie jego nazwy.
   - Jeśli pliku nie można otworzyć, wyświetlany jest komunikat o błędzie, a program kończy działanie.

2. **Odczyt wymiarów:**
   - Pierwsza linia pliku jest odczytywana w celu ustalenia liczby wierszy (`r`) i kolumn (`c`).

3. **Alokacja pamięci:**
   - Macierz o rozmiarze `r x c` jest dynamicznie alokowana.
   - Jeśli alokacja pamięci się nie powiedzie, wyświetlany jest komunikat o błędzie.

4. **Wypełnianie macierzy:**
   - Pozostałe linie są odczytywane w celu wypełnienia macierzy, wiersz po wierszu.

5. **Zwracanie macierzy:**
   - Funkcja zwraca wskaźnik do wypełnionej macierzy.

### **Przebieg głównego programu**
W głównym programie funkcja `initMatrixFromFile` jest wywoływana do załadowania zarówno macierzy, jak i wektora wyników:

```c
int r, c;
double *matrix = initMatrixFromFile("input.txt", &r, &c);
double *res = initMatrixFromFile("input2.txt", &r, &c);
```

#### **Walidacja macierzy**
- Upewnij się, że liczba wierszy i kolumn w plikach wejściowych jest zgodna z wymaganiami procesu eliminacji Gaussa.
- Plik macierzy i plik wektora wyników powinny używać spójnych wymiarów.

---

## Obsługa błędów

### **Plik nie został znaleziony:**
Jeśli pliku nie można otworzyć, program wyświetli:
```
Błąd: Nie można otworzyć pliku <nazwa_pliku>
```

### **Nieprawidłowe wymiary macierzy:**
Jeśli wymiary macierzy są niekompletne lub nieprawidłowe, program może zakończyć działanie lub zachowywać się w nieoczekiwany sposób.

### **Błąd alokacji pamięci:**
Jeśli program nie może zaalokować pamięci dla macierzy, wyświetli:
```
Błąd: Alokacja pamięci nie powiodła się.
```
---

## Przykładowe użycie
### **Pliki wejściowe:**
- `input.txt`
  ```
  2 2
  2 3
  1 -1

  ```
- `input2.txt`
  ```
  2 1
  8
  -1

  ```

### **Polecenie:**
Skompiluj i uruchom program:
```bash
gcc -o program main.c gaus.c read.c -lm
./program
```