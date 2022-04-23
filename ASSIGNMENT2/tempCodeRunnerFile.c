int q3(const airport_t *src, int n, const connection_t connections[n][n])
{
    pv pv_arr[n];
    for (int i = 0; i < n; i++)
    {
        pv_arr[i].visited = 0;
        pv_arr[i].parent = -1;
    }
    int source = src->num_id, flag = 0;
    cycle(n, pv_arr, connections, source, source, &flag);
    return flag;
}
