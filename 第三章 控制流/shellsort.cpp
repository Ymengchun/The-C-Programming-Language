/* ϣ�����򣺰�����˳���v[0]...v[length-1]�������� */
void shellsort(int v[], int length)
{
    int gap, i, j, temp;

    for (gap = length/2; gap > 0; gap /= 2)							/* �𲽼�Сgap */
    {
        for (i = gap; i < length; i++)
        {
            for (j = i - gap; j >= 0 && v[j] > v[j+gap]; j -= gap)
            {
                temp = v[j];										/* ���� */
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
        }
    }
}
