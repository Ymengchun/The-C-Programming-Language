/* 希尔排序：按递增顺序对v[0]...v[length-1]进行排序 */
void shellsort(int v[], int length)
{
    int gap, i, j, temp;

    for (gap = length/2; gap > 0; gap /= 2)							/* 逐步减小gap */
    {
        for (i = gap; i < length; i++)
        {
            for (j = i - gap; j >= 0 && v[j] > v[j+gap]; j -= gap)
            {
                temp = v[j];										/* 交换 */
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
        }
    }
}
