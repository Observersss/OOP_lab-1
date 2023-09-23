using namespace std;
class algorithm {
private:
public:
    void print_mas(int *mas, int size = 0) {
        for (int i = 0; i < size; i += 1) {
            cout << "mas[" << i << "] = ";
            cout << mas[i] << endl;
        }
    }

//Algorithm insertion_sort
    void insertion_sort(int *mas, int size = 0) {
        //Створення додаткових змінних та виконання алгоритму
        int buf = 0;
        int i, j;

        for (i = 1; i < size; i += 1) {
            buf = mas[i];
            j = i - 1;
            while (j >= 0 && mas[j] > buf) {
                mas[j + 1] = mas[j];
                j--;
            }
            mas[j + 1] = buf;
        }

    }

//Algorithm quicksort
// Разделение по схеме Lomuto
    int partition(int a[], int start, int end) {
        // Выбираем крайний правый элемент в качестве опорного элемента массива
        int pivot = a[end];

        // элементы, меньшие точки поворота, будут перемещены влево от `pIndex`
        // элементы больше, чем точка поворота, будут сдвинуты вправо от `pIndex`
        // равные элементы могут идти в любом направлении
        int pIndex = start;

        // каждый раз, когда мы находим элемент, меньший или равный опорному, `pIndex`
        // увеличивается, и этот элемент будет помещен перед опорной точкой.
        for (int i = start; i < end; i++) {
            if (a[i] <= pivot) {
                swap(a[i], a[pIndex]);
                pIndex++;
            }
        }

        // поменять местами `pIndex` с пивотом
        swap(a[pIndex], a[end]);

        // вернуть `pIndex` (индекс опорного элемента)
        return pIndex;
    }

// Процедура быстрой сортировки
    void quicksort(int a[], int start, int end) {
        // базовое условие
        if (start >= end) {
            return;
        }

        // переставить элементы по оси
        int pivot = partition(a, start, end);

        // повторяем подмассив, содержащий элементы, меньшие опорной точки
        quicksort(a, start, pivot - 1);

        // повторяем подмассив, содержащий элементы, превышающие точку опоры
        quicksort(a, pivot + 1, end);
    }
};
