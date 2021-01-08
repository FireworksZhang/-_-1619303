#include"sort.h"

SortSolution::SortSolution()
{
	srand((int)time(0));
	for (int i = 0; i < 10; i++)
	{
		data[i].clear();
		cout << "�������ɵ�" << i + 1 << "�����ݣ�";
		if (i == 0)
		{
			for (int j = 1; j <= CountNumber; j++)
				data[i].push_back(j);
		}//��һ������
		else if (i == 9)
		{
			for (int j = CountNumber; j >= 1; j--)
				data[i].push_back(j);
		}//���һ������
		else
		{
			for (int j = 1; j <= CountNumber; j++)
			{
				data[i].push_back(rand());
			}
		}//ʣ������
		cout << endl;
	}
	ofstream out("data.dat", ios::out);
	ifstream in("data.dat", ios::in);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < data[i].size(); j++)
		{
			out << data[i][j] << " ";
		}
	}
	out.close();
	vector<int> copy[10];
	for (int i = 0; i < 10; i++)
	{
		copy[i].assign(data[i].begin(), data[i].end());
	}
	for (int s = 1; s <= 8; s++)
	{
		for (int i = 0; i < 10; i++)
		{
			data[i].assign(copy[i].begin(), copy[i].end());
		}

		switch (s)
		{
		case 1:
			cout << s << ".��������" << endl;
			Insert_Sort();
			break;
		case 2:
			cout << endl << s << ".ϣ������" << endl;
			Shell_Sort();
			break;
		case 3:
			cout << endl << s << ".ð������" << endl;
			Bubble_Sort();
			break;
		case 4:
			cout << endl << s << ".��������" << endl;
			Quick_Sort();
			break;
		case 5:
			cout << endl << s << ".ѡ������" << endl;
			Select_Sort();
			break;
		case 6:
			cout << endl << s << ".������" << endl;
			Heap();
			break;
		case 7:
			cout << endl << s << ".�鲢����" << endl;
			Merge_Sort();
			break;
		case 8:
			cout << endl << s << ".��������" << endl;
			Radix_Sort();
			break;
		}

		if (check())
		{
			cout << "����ɹ�";
		}
		else
		{
			cout << "����ʧ��" << endl;
			break;
		}
	}
}

bool SortSolution::check()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < CountNumber - 1; j++)
		{
			if (data[i][j] > data[i][j + 1])
				return false;
		}
	}
	return true;
}

void SortSolution::Insert_Sort()
{

	for (int i = 0; i < 10; i++)
	{
		ftime(&startTime);
		insertsort(data[i]);
		ftime(&endTime);
		cout << "��" << i + 1 << "�����ݻ���ʱ��:" << (endTime.time - startTime.time) * 1000 + (endTime.millitm - startTime.millitm) << "ms" << endl;
	}
}

void SortSolution::insertsort(vector<int>& a)
{
	int n = a.size();
	for (int i = 1; i < n; i++) {
		for (int j = i; j > 0; j--) {
			if (a[j] < a[j - 1]) {
				swap(a[j], a[j - 1]);
			}
			else {
				break;
			}
		}
	}

}

void SortSolution::Shell_Sort()
{
	for (int i = 0; i < 10; i++)
	{
		ftime(&startTime);
		ShellSort(data[i]);
		ftime(&endTime);
		cout << "��" << i + 1 << "�����ݻ���ʱ��:" << (endTime.time - startTime.time) * 1000 + (endTime.millitm - startTime.millitm) << "ms" << endl;
	}
}

void SortSolution::ShellSort(vector<int>& a)
{
	int increment = a.size() / 2;
	while (increment)
	{
		for (int i = increment; i < a.size(); i += 1)//�Ը��ӱ���ֱ�Ӳ�������
		{
			int temp = a[i], j;
			for (j = i - increment; j >= 0 && temp < a[j]; j -= increment)
			{
				a[j + increment] = a[j];
			}
			a[j + increment] = temp;
		}
		increment /= 2;
	}


}

void SortSolution::Bubble_Sort()
{
	for (int i = 0; i < 10; i++)
	{
		ftime(&startTime);
		bubblesort(data[i]);
		ftime(&endTime);
		cout << "��" << i + 1 << "�����ݻ���ʱ��:" << (endTime.time - startTime.time) * 1000 + (endTime.millitm - startTime.millitm) << "ms" << endl;
	}
}

void SortSolution::bubblesort(vector<int>& a)
{
	int n = a.size();
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
		}
	}
}

void SortSolution::Quick_Sort()
{
	int l = 0, r = CountNumber - 1;
	for (int i = 0; i < 10; i++)
	{
		ftime(&startTime);
		quicksort(data[i], l, r);
		ftime(&endTime);
		cout << "��" << i + 1 << "�����ݻ���ʱ��:" << (endTime.time - startTime.time) * 1000 + (endTime.millitm - startTime.millitm) << "ms" << endl;
	}
}

void SortSolution::quicksort(vector<int>& a, int l, int r)
{
	int	mid = a[(l + r) / 2];
	int i = l, j = r;
	do
	{
		while (a[j] > mid)	j--;
		while (a[i] < mid)	i++;

		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (l < j)	quicksort(a, l, j);
	if (i < r)	quicksort(a, i, r);
}

void SortSolution::Select_Sort()
{
	for (int i = 0; i < 10; i++)
	{
		ftime(&startTime);
		selectSort(data[i]);
		ftime(&endTime);
		cout << "��" << i + 1 << "�����ݻ���ʱ��:" << (endTime.time - startTime.time) * 1000 + (endTime.millitm - startTime.millitm) << "ms" << endl;
	}
}

void SortSolution::selectSort(vector<int>& v)
{
	int n = v.size();
	for (int i = 0; i < n - 1; i++) {
		int index = 0;
		for (int j = 1; j < n - i; j++) {
			if (v[j] > v[index]) {
				index = j;
			}
		}
		swap(v[index], v[n - 1 - i]);
	}
}

void SortSolution::Heap()
{
	for (int i = 0; i < 10; i++)
	{
		ftime(&startTime);
		heapSort(data[i]);
		ftime(&endTime);
		cout << "��" << i + 1 << "�����ݻ���ʱ��:" << (endTime.time - startTime.time) * 1000 + (endTime.millitm - startTime.millitm) << "ms" << endl;
	}
}

void SortSolution::adjust(vector<int>& arr, int len, int index)
{
	int left = 2 * index + 1; // index�����ӽڵ�
	int right = 2 * index + 2;// index�����ӽڵ�

	int maxIdx = index;
	if (left<len && arr[left] > arr[maxIdx])     maxIdx = left;
	if (right<len && arr[right] > arr[maxIdx])     maxIdx = right;

	if (maxIdx != index)
	{
		swap(arr[maxIdx], arr[index]);
		adjust(arr, len, maxIdx);
	}

}

void SortSolution::heapSort(vector<int>& arr)
{
	int size = arr.size();
	// ��������ѣ������һ����Ҷ�ӽڵ����ϣ�
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		adjust(arr, size, i);
	}

	// ���������
	for (int i = size - 1; i >= 1; i--)
	{
		swap(arr[0], arr[i]);           // ����ǰ���ķ��õ�����ĩβ
		adjust(arr, i, 0);              // ��δ�������Ĳ��ּ������ж�����
	}
}

void SortSolution::Merge_Sort()
{
	for (int i = 0; i < 10; i++)
	{
		ftime(&startTime);
		mergeSort(data[i]);
		ftime(&endTime);
		cout << "��" << i + 1 << "�����ݻ���ʱ��:" << (endTime.time - startTime.time) * 1000 + (endTime.millitm - startTime.millitm) << "ms" << endl;
	}
}

void SortSolution::merge(vector<int>& v, int left, int mid, int right)
{
	vector<int> temp = v;
	int i = left, j = mid + 1;
	int index = left;
	while (i <= mid || j <= right) {
		if (i > mid) {
			v[index++] = temp[j];
			j++;
		}
		else if (j > right) {
			v[index++] = temp[i];
			i++;
		}
		else if (temp[i] < temp[j]) {
			v[index++] = temp[i];
			i++;
		}
		else {
			v[index++] = temp[j];
			j++;
		}
	}

}

void SortSolution::merge_Sort(vector<int>& v, int left, int right)
{
	if (left >= right) return;
	int mid = (left + right) / 2;
	merge_Sort(v, left, mid);
	merge_Sort(v, mid + 1, right);
	if (v[mid] > v[mid + 1]) {
		merge(v, left, mid, right);
	}
}

void SortSolution::mergeSort(vector<int>& v)
{
	int n = v.size();
	merge_Sort(v, 0, n - 1);
}

void SortSolution::Radix_Sort()
{
	for (int i = 0; i < 10; i++)
	{
		ftime(&startTime);
		radixsort(data[i]);
		ftime(&endTime);
		cout << "��" << i + 1 << "�����ݻ���ʱ��:" << (endTime.time - startTime.time) * 1000 + (endTime.millitm - startTime.millitm) << "ms" << endl;
	}
}

int SortSolution::getMax(vector<int>& v)
{
	int n = v.size();
	int mx = v[0];
	for (int i = 1; i < n; i++)
		if (v[i] > mx)
			mx = v[i];
	return mx;
}

void SortSolution::countSort(vector<int>& v, int exp)

{
	int n = v.size();
	int output[CountNumber];
	int i, count[10] = { 0 };

	for (i = 0; i < n; i++)
		count[(v[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--)
	{
		output[count[(v[i] / exp) % 10] - 1] = v[i];
		count[(v[i] / exp) % 10]--;
	}

	for (i = 0; i < n; i++)
		v[i] = output[i];
}

void SortSolution::radixsort(vector<int>& v)
{
	int m = getMax(v);
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(v, exp);
}