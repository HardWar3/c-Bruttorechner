#ifndef _USER_DATEN
#define _USER_DATEN 1

#include "assert.h"
#include "stdio.h"
#include "stdlib.h"


#ifdef __cplusplus
extern "C" {
#endif

struct user_daten {
	int af; /**< 1 wenn faktorverfahren gewählt wurde */
	int ajahr; /**< geburtsjahr */
	int alter1; /**< wenn alter grösser 64 ist wird wert auf 1 */
	double entsch; /**< in vkapa und vmt enthaltene entschädigungen */
	double f; /**< eingetragener faktor mit dreinachkommastellen */
	double jfreib; /**< jahrfreibetrag für die ermittlung der lohnsteuer */
	double jhinzu; /**< jahreshinzurechnungsbetrag für die ermittlung der lohnsteuer */
	double jre4; /**< jahresgehalt */
	double jre4ent; /**< in jre4 enthaltene entschädigungen in cent */
	double jvbez; /**< in jre4 enthaltene versorgungsbezüge in cent */
	int krv; /**< rentenversicherung */
	double kvz; /**< kassenindividueller zusatzbeitragssatz */
	int lzz; /**< lohnzahnlungszeitraum 1->jahr 2->monat 3->woche 4->tag */
	double lzzfreib; /**< freibetrag lohnsteuerabzugsmerkmal */
	double lzzhinzu; /**< hinzurechnungsbetrag lohnsteuerabzugsmerkmal */
	double pkpv; /**< private krankenversicherungs beiträge */
	int pkv; /**< krankenkasse ob gesetzlich oder privat mit oder ohne zuschuss */
	int pvs; /**< sozialen pflegeversicherung sachen oder nicht sachsen */
	int pvz; /**< sozialen pflegeversicherung ü23 ohne kinder ja/nein */
	int r; /**< relegion */
	double re4; /**< bruttogehalt */
	double sonstb; /**< sonstige bezüge ( ohne vergütung aus mehrjähr. tätigkeit ) in cent */
	double sonstent; /**< in sonstb enthaltene entschädigungen in cent */
	double sterbe; /**< sterbegeld bei versorgungsbezüge in cent */
	int stkl; /**< steuerklasse */
	double vbez; /**< in re4 enthaltene versorgungsbezüge in cent */
	double vbezm; /**< versorgungsbezüge im januar 2005 für den ersten vollen monat in cent */
	double vbezs; /**< vorraussichtliche sonderzahlungen von versorgungsbezügen in cent */
	double vbs; /**< in sonstb enthaltene versorgungsbezüge einschliesslich sterbegeld in cent */
	int vjahr; /**< jahr in dem er versorgungsbezug erstmalig gewährt wurde */
	double vkapa; /**< entschädigungen/kapitalsausz./abfindung/nachzahlung bei versorgungs. für mehrere jahre in cent */
	double vmt; /**< entschädigungen und vergütung für mehrjährige tätigkeit in cent bei versorgungsbezüge */
	double zkf; /**< kinderfreibetrag */
	int zmvb; /**< zahl der monate für die im kalenderjahr versorgungsbezüge gezahlt werden ( nur erfolg bei lzz = 1 ) */
	double bk;
	double bks;
	double bkv;
	double lstlzz;
	double solzlzz;
	double solzs;
	double solzv;
	double sts;
	double stv;
	double vkvlzz;
	double vkvsonst;
	double vfrb;
	double vfrbs1;
	double vfrbs2;
	double wvfrb;
	double wvfrbm;
	double wvfrbo;
	double alte; /**< 2 stellennachdemkomma */
	double anp;
	double anteil1;
	double bbgkvpv;
	double bbgrv;
	double bmg; /**< 2 stellennachdemkomma */
	double diff;
	double efa;
	double fvb; /**< 2 stellennachdemkomma */
	double fvbso; /**< 2 stellennachdemkomma */
	double fvbz;
	double fvbzso;
	double gfb;
	double hbalte;
	double hfvb;
	double hfvbz; /**< 2 stellennachdemkomma */
	double hfvbzso; /**< 2 stellennachdemkomma */
	double hoch;
	int j;
	double jbmg;
	double jlfreib; /**< 2 stellennachdemkomma */
	double jlhinzu; /**< 2 stellennachdemkomma */
	double jw;
	int k;
	int kennvmt;
	double kfb;
	double kvsatzag; /**< 5 stellennachdemkomma */
	double kvsatzan; /**< 5 stellennachdemkomma */
	int kztab;
	double lstjahr;
	double lst1;
	double lst2;
	double lst3;
	double lstoso;
	double lstso;
	double mist;
	double pvsatzag; /**< 5 stellennachdemkomma */
	double pvsatzan; /**< 5 stellennachdemkomma */
	double rvsatzan; /**< 4 stellennachdemkomma */
	double rw; /**< gleitkommadarstellung */
	double sap;
	double solzfrei;
	double solzj;
	double solzmin;
	double st;
	double st1;
	double st2;
	double stovmt;
	double tab1;
	double tab2;
	double tab3;
	double tab4;
	double tab5;
	double tbsvorv; /**< 2 stellennachdemkomma */
	double vbezb;
	double vbezbso;
	double vergl;
	double vhb; /**< 2 stellennachdemkomma */
	double vkv;
	double vsp; /**< 2 stellennachdemkomma */
	double vspn; /**< 2 stellennachdemkomma */
	double vsp1; /**< 2 stellennachdemkomma */
	double vsp2; /**< 2 stellennachdemkomma */
	double vsp3; /**< 2 stellennachdemkomma */
	double w1stkl5;
	double w2stkl5;
	double w3stkl5;
	double x; /**< 2 stellennachdemkomma */
	double y; /**< 6 stellennachdemkomma */
	double zre4; /**< 2 stellennachdemkomma */
	double zre4j; /**< 2 stellennachdemkomma */
	double zre4vp; /**< 2 stellennachdemkomma */
	double ztabfb; /**< 2 stellennachdemkomma */
	double zvbez; /**< 2 stellennachdemkomma */
	double zvbezj; /**< 2 stellennachdemkomma */
	double zve; /**< 2 stellennachdemkomma */
	double zx;
	double zzx;
	double rv;
	double av;
	double kv;
	double pv_an;
	double pv_ag;
	double kst;
	double gesamt_st;
	double sum_sozialv_an;
	double sum_sozialv_ag;
	double netto_lohn;
	double gesamt_belast_ag;
	double id_nummer;
};

extern void user_daten_init(struct user_daten *);

extern struct user_daten * user_daten_new(void);

extern void user_daten_free(struct user_daten *);

#ifdef __cplusplus
}
#endif

#endif
