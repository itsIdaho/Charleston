    void countNumTypes(long *x, int anz, int *nT, int maxStellen)
    {
        int anzStellen;
        //initialisieren
        for(int i = 0; i<maxStellen; i++)
        {
           nT[i] = 0;
        }
        for (int i = 0; i < anz; i++)
        {
            anzStellen = log10(x[i]);
            nT[anzStellen]++;
        }    
        
    }
