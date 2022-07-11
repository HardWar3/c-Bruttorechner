#include "assert.h"
#include "stdio.h"
#include "stdlib.h"
#include "user_daten.h"

static void user_daten_init(struct user_daten *, int);

static void
user_daten_init(struct user_daten *p, int initial)
{
	if (!initial)
		user_daten_free(p);

	p->af= 0;
	p->ajahr= 0;
	p->alter1= 0;
	p->entsch= 0.0;
	p->f= 0.0;
	p->jfreib= 0.0;
	p->jhinzu= 0.0;
	p->jre4= 0.0;
	p->jre4ent= 0.0;
	p->jvbez= 0.0;
	p->krv= 0;
	p->kvz= 0.0;
	p->lzz= 0;
	p->lzzfreib= 0.0;
	p->lzzhinzu= 0.0;
	p->pkpv= 0.0;
	p->pkv= 0;
	p->pvs= 0;
	p->pvz= 0;
	p->r= 0;
	p->re4= 0.0;
	p->sonstb= 0.0;
	p->sonstent= 0.0;
	p->sterbe= 0.0;
	p->stkl= 0;
	p->vbez= 0.0;
	p->vbezm= 0.0;
	p->vbezs= 0.0;
	p->vbs= 0.0;
	p->vjahr= 0;
	p->vkapa= 0.0;
	p->vmt= 0.0;
	p->zkf= 0.0;
	p->zmvb= 0;
	p->bk= 0.0;
	p->bks= 0.0;
	p->bkv= 0.0;
	p->lstlzz= 0.0;
	p->solzlzz= 0.0;
	p->solzs= 0.0;
	p->solzv= 0.0;
	p->sts= 0.0;
	p->stv= 0.0;
	p->vkvlzz= 0.0;
	p->vkvsonst= 0.0;
	p->vfrb= 0.0;
	p->vfrbs1= 0.0;
	p->vfrbs2= 0.0;
	p->wvfrb= 0.0;
	p->wvfrbm= 0.0;
	p->wvfrbo= 0.0;
	p->alte= 0.0;
	p->anp= 0.0;
	p->anteil1= 0.0;
	p->bbgkvpv= 0.0;
	p->bbgrv= 0.0;
	p->bmg= 0.0;
	p->diff= 0.0;
	p->efa= 0.0;
	p->fvb= 0.0;
	p->fvbso= 0.0;
	p->fvbz= 0.0;
	p->fvbzso= 0.0;
	p->gfb= 0.0;
	p->hbalte= 0.0;
	p->hfvb= 0.0;
	p->hfvbz= 0.0;
	p->hfvbzso= 0.0;
	p->hoch= 0.0;
	p->j= 0;
	p->jbmg= 0.0;
	p->jlfreib= 0.0;
	p->jlhinzu= 0.0;
	p->jw= 0.0;
	p->k= 0;
	p->kennvmt= 0;
	p->kfb= 0.0;
	p->kvsatzag= 0.0;
	p->kvsatzan= 0.0;
	p->kztab= 0;
	p->lstjahr= 0.0;
	p->lst1= 0.0;
	p->lst2= 0.0;
	p->lst3= 0.0;
	p->lstoso= 0.0;
	p->lstso= 0.0;
	p->mist= 0.0;
	p->pvsatzag= 0.0;
	p->pvsatzan= 0.0;
	p->rvsatzan= 0.0;
	p->rw= 0.0;
	p->sap= 0.0;
	p->solzfrei= 0.0;
	p->solzj= 0.0;
	p->solzmin= 0.0;
	p->st= 0.0;
	p->st1= 0.0;
	p->st2= 0.0;
	p->stovmt= 0.0;
	p->tab1= 0.0;
	p->tab2= 0.0;
	p->tab3= 0.0;
	p->tab4= 0.0;
	p->tab5= 0.0;
	p->tbsvorv= 0.0;
	p->vbezb= 0.0;
	p->vbezbso= 0.0;
	p->vergl= 0.0;
	p->vhb= 0.0;
	p->vkv= 0.0;
	p->vsp= 0.0;
	p->vspn= 0.0;
	p->vsp1= 0.0;
	p->vsp2= 0.0;
	p->vsp3= 0.0;
	p->w1stkl5= 0.0;
	p->w2stkl5= 0.0;
	p->w3stkl5= 0.0;
	p->x= 0.0;
	p->y= 0.0;
	p->zre4= 0.0;
	p->zre4j= 0.0;
	p->zre4vp= 0.0;
	p->ztabfb= 0.0;
	p->zvbez= 0.0;
	p->zvbezj= 0.0;
	p->zve= 0.0;
	p->zx= 0.0;
	p->zzx= 0.0;
	p->rv= 0.0;
	p->av= 0.0;
	p->kv= 0.0;
	p->pv_an= 0.0;
	p->pv_ag= 0.0;
	p->kst= 0.0;
	p->gesamt_st= 0.0;
	p->sum_sozialv_an= 0.0;
	p->sum_sozialv_ag= 0.0;
	p->netto_lohn= 0.0;
	p->gesamt_belast_ag= 0.0;
	p->id_nummer= 0.0;
}

void
user_daten_init(struct user_daten *p)
{
	user_daten_init(p, 0);
}

struct user_daten *
user_daten_new(void)
{
	struct user_daten *p;

	p= calloc((size_t) 1, sizeof(struct user_daten));

	user_daten_init(p, 1);

	return(p);
}

void
user_daten_free(struct user_daten *p)
{
}
