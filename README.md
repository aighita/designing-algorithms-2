## Problema 1 - Numarare

#### Prezentare Generală
Acest program citește două grafuri direcționate dintr-un fișier de intrare, identifică
muchiile comune între cele două grafuri, construiește un nou graf format din aceste
muchii comune și apoi calculează numărul de drumuri distincte de la nodul 1 la nodul
N în noul graf.

#### Funcții

* **findCommonEdges**: Găsește muchiile comune între două grafuri.
  - **Parametri**:
    - `graph1_adj`: Lista de adiacență a primului graf.
    - `graph2_adj`: Lista de adiacență a celui de-al doilea graf.
    - `N`: Numărul de noduri în grafuri.
  - **Returnează**: O nouă listă de adiacență reprezentând graful format din muchiile comune ale celor două grafuri.

* **find_all_paths_1_to_N**: Calculează numărul de drumuri distincte de la nodul 1 la nodul N folosind programarea dinamică.
  - **Parametri**: 
    - `graph`: Lista de adiacență a grafului.
  - **Returnează**: Numărul de drumuri distincte de la nodul 1 la nodul N.

* **main**: Citește datele de intrare, identifică muchiile comune, construiește graful comun, calculează numărul de drumuri distincte și scrie rezultatul în fișierul de ieșire.

#### Complexitate
* **Complexitate de Timp**:
  * Funcția `findCommonEdges`: O(N + M), unde N este numărul de noduri și M este numărul de muchii, deoarece fiecare muchie este verificată o dată.
  * Funcția `find_all_paths_1_to_N`: O(N + M), datorită parcurgerii grafului și actualizării valorilor din vectorul DP.

* **Complexitate de Spațiu**:
  * Spațiul utilizat este O(N^2) pentru stocarea listelor de adiacență și a matricii de muchii, și O(N) pentru vectorul DP.


## Problema 2 - Trenuri

#### Prezentare Generală
Acest program citește un graf aciclic direcționat (DAG) care reprezintă rutele trenurilor dintr-un fișier de intrare, efectuează o sortare
topologică a grafului și apoi găsește cel mai lung drum de la un nod sursă specificat la un nod destinație folosind programarea dinamică (DP).

#### Funcții

* **printUnorderedMap**: Afișează conținutul unei unordered map în fișierul de jurnal.
* **topologicalSort**: Realizează o sortare topologică a grafului.
* **topologicalSort2**: O sortare topologică alternativă care asigură atingerea nodului destinație.
* **printVector**: Afișează un vector de stringuri în fișierul de jurnal.
* **find_max_path**: Găsește lungimea maximă a drumului în ordinea topologică sortată.
* **main**: Citește datele de intrare, realizează sortarea topologică, găsește cel mai lung drum și scrie rezultatul.

#### Complexitate
* **Complexitate de Timp**:
  * Sortarea topologică: O(V + E), unde V este numărul de noduri și E este numărul de muchii.
  * Găsirea celui mai lung drum: O(V + E), deoarece iterează prin noduri și muchii o dată.

* **Complexitate de Spațiu**:
  * Sortarea topologică: O(V + E), pentru stocarea in-degree-urilor, a cozii și a ordinii sortate.
  * Găsirea celui mai lung drum: O(V), pentru stocarea tabelului de programare dinamică (DP).

## Problema 3 - Drumuri

#### Prezentare Generală
Programul citește un graf ponderat direcționat dintr-un fișier de intrare, aplică
algoritmul Dijkstra pentru a calcula distanțele minime de la trei noduri sursă
specificate, și apoi găsește costul minim al unui drum specific în graf.

#### Funcții

* **dijkstra**: Aplică algoritmul Dijkstra pentru a calcula distanțele minime de la un nod sursă la toate celelalte noduri din graf.
  - **Parametri**:
    - `start`: Nodul sursă de la care se calculează distanțele.
    - `n`: Numărul de noduri în graf.
    - `adj`: Lista de adiacență a grafului.
  - **Returnează**: Un vector de distanțe minime de la nodul sursă la toate celelalte noduri.

* **main**: Citește datele de intrare, construiește grafurile, aplică algoritmul Dijkstra de trei ori, calculează costul minim al drumului
specificat și scrie rezultatul în fișierul de ieșire.

#### Complexitate
* **Complexitate de Timp**:
  * Algoritmul Dijkstra: O((V + E) log V), unde V este numărul de noduri și E este numărul de muchii, datorită utilizării unei cozi de priorități.

* **Complexitate de Spațiu**:
  * Spațiul utilizat este O(V + E) pentru stocarea listelor de adiacență și O(V) pentru vectorul de distanțe minime.

#### Detalii de Implementare
1. **Citirea datelor de intrare**:
   - Programul citește numărul de noduri (n) și numărul de muchii (m).
   - Se citesc muchiile grafului, fiecare muchie fiind definită de două noduri și o greutate.
   - Se citesc cele trei noduri sursă (x, y, z).

2. **Aplicarea algoritmului Dijkstra**:
   - Se aplică Dijkstra de la nodul `x` pentru a obține distanțele minime de la `x` la toate celelalte noduri.
   - Se aplică Dijkstra de la nodul `y` pentru a obține distanțele minime de la `y` la toate celelalte noduri.
   - Se aplică Dijkstra pe graful transpus de la nodul `z` pentru a obține distanțele minime de la toate celelalte noduri la `z`.

3. **Calcularea costului minim**:
   - Se iterează prin toate muchiile grafului și se calculează costul total pentru drumurile care trec prin acea muchie, combinând distanțele minime obținute anterior.
   - Se determină costul minim dintre toate aceste drumuri.

4. **Scrierea rezultatului**:
   - Rezultatul (costul minim al drumului specificat) este scris în fișierul de ieșire `drumuri.out`.

## Problema 4 - Scandal

#### Funcții

* **get_complement**: Returnează complementul unei variabile date.
  - **Parametri**:
    - `var`: Variabila pentru care se calculează complementul.
  - **Returnează**: Complementul variabilei date.

* **read_input**: Citește datele de intrare din fișierul `scandal.in` și construiește grafurile corespunzătoare.

* **depth_first_search**: Realizează o parcurgere în adâncime (DFS) în graful original.
  - **Parametri**:
    - `node`: Nodul de la care începe parcurgerea.
  - Nu returnează nimic.

* **depth_first_search_transpose**: Realizează o parcurgere în adâncime (DFS) în graful transpus.
  - **Parametri**:
    - `node`: Nodul de la care începe parcurgerea.
* **solve**: Rezolvă problema 2-SAT folosind algoritmul **Kosaraju** pentru a găsi componentele tare conexe și determină soluția optimă.

* **main**: Funcția principală care citește datele de intrare, rezolvă problema și scrie rezultatul în fișierul de ieșire.

#### Complexitate
* **Complexitate de Timp**:
  * Algoritmul de parcurgere în adâncime (DFS): O(V + E), unde V este numărul de noduri și E este numărul de muchii.
  * Algoritmul Kosaraju pentru găsirea componentelor tare conexe: O(V + E), deoarece constă în două parcurgeri DFS.

* **Complexitate de Spațiu**:
  * Spațiul utilizat este O(V + E) pentru stocarea listelor de adiacență și a grafului transpus.
  * Spațiul utilizat pentru stocarea soluției și a vectorilor de vizitare este O(V).
