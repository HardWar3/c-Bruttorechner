#include <stdio.h>
#include <stdlib.h>

#include "user_daten.h"

struct user_daten* new_daten() {

	struct user_daten *user;

	user = calloc( 1, sizeof( struct user_daten ));

	assert( user ); 

// ---------------------------------------------------------------------------------------------------------------
// Eingabeparameter
// ---------------------------------------------------------------------------------------------------------------

	user -> af = 0;			// int			// 1 wenn faktorverfahren gewählt wurde
	user -> ajahr = 2000;		// int			// geburtsjahr
	user -> alter1 = 0;		// int			// wenn alter grösser 64 ist wird wert auf 1
	user -> entsch = 0;		// long			// in vkapa und vmt enthaltene entschädigungen
	user -> f = 0.000;		// double 3 komma	// eingetragener faktor mit dreinachkommastellen
	user -> jfreib = 0;		// long			// jahresfreibetrag für die ermittlung der lohnsteuer
	user -> jhinzu = 0;		// long		 	// jahreshinzurechnungsbetrag für die ermittlung der lohnsteuer
	user -> jre4 = 0;		// long		 	// jahresgehalt 
	user -> jre4ent = 0;		// long		 	// in jre4 enthaltene entschädigungen in cent
	user -> jvbez = 0;		// long		 	// in jre4 enthaltene versorgungsbezüge in cent	
	user -> krv = 0;		// int			// rentenversicherung
	user -> kvz = 0.00;		// double 2 komma	// kassenindividueller zusatzbeitragssatz
	user -> lzz = 1;		// int			// lohnzahnlungszeitraum 1->jahr 2->monat 3->woche 4 tag
	user -> lzzfreib = 0;		// long		 	// freibetrag lohnsteuerabzugsmerkmal
	user -> lzzhinzu = 0;		// long		 	// hinzurechnungsbetrag lohnsteuerabzugsmerkmal 
	user -> pkpv = 0;		// long		 	// private krankenversicherungs beiträge 
	user -> pkv = 0;		// int 			// krankenkasse ob gesetzlich oder privat mit oder ohne zuschuss
	user -> pvs = 0;		// int			// sozialen pflegeversicherung sachsen nicht sachen
	user -> pvz = 0;		// int			// sozialen pflegeversicherung ü23 ohne kinder ja/nein
	user -> r = 0;			// int			// relegion
	user -> re4 = 0;		// long		 	// bruttogehalt
	user -> sonstb = 0;		// long		 	// sonstige bezüge ( ohne vergütung aus mehrjähr. tätigkeit ) in cent
	user -> sonstent = 0;		// long		 	// in sonstb enthaltene entschädigungen in cent
	user -> sterbe = 0;		// long		 	// sterbegeld bei versorgungsbezügen sowie kapital/abfindung in cent
	user -> stkl = 1;		// int			// steuerklasse
	user -> vbez = 0;		// long		 	// in re4 enthaltene versorgungbezüge in cent
	user -> vbezm = 0;		// long		 	// versorgungsbezüge im januar 2005 für den ersten vollen monat in cent 
	user -> vbezs = 0;		// long		 	// vorraussichliche sonderzahlungen von versorgungsbezügen in cent
	user -> vbs = 0;		// long		 	// in sonstb enthaltene versorgungsbezüge einschliesslich sterbegeld in cent
	user -> vjahr = 0;		// int			// jahr in dem er versorgungsbezug erstmalig gewährt wurde
	user -> vkapa = 0;		// long		 	// entschädigungen/kapitalausz./abfindung/nachzahlung bei versorgungs. für mehrere jahre in cent
	user -> vmt = 0;		// long		 	// entschädigungen und vergütung für mehrjährige tätigkeit in cent bei versorgungsbezüge
	user -> zkf = 0.0;		// double 1 komma	// kinderfreibetrag
	user -> zmvb = 0;		// int			// zahl der monate für die im kalenderjahr verorgungsbezüge gezahlt werden ( nur erfolg bei lzz = 1 )

// ---------------------------------------------------------------------------------------------------------------
// Ausgabeparameter 
// ---------------------------------------------------------------------------------------------------------------
	
	user -> bk = 0;			// long 
	user -> bks = 0;		// long
	user -> bkv = 0;		// long
	user -> lstlzz = 0;		// long
	user -> solzlzz = 0;		// long
	user -> solzs = 0;		// long
	user -> solzv = 0;		// long
	user -> sts = 0;		// long
	user -> stv = 0;		// long
	user -> vkvlzz = 0;		// long
	user -> vkvsonst = 0;		// long

// ---------------------------------------------------------------------------------------------------------------
// interne Felder or Ausgabeparameter DBA
// ---------------------------------------------------------------------------------------------------------------

	user -> vfrb = 0;		// long
	user -> vfrbs1 = 0;		// long
	user -> vfrbs2 = 0;		// long
	user -> wvfrb = 0;		// long
	user -> wvfrbm = 0;		// long
	user -> wvfrbo = 0;		// long

// ---------------------------------------------------------------------------------------------------------------
// Interne Felder
// ---------------------------------------------------------------------------------------------------------------

	user -> alte = 0.00;		// double 2 stellennachdemkomma
	user -> anp = 0;		// long
	user -> anteil1 = 0;		// long
	user -> bbgkvpv = 0;		// long
	user -> bbgrv = 0;		// long
	user -> bmg = 0.00;		// double 2 stellennachdemkomma
	user -> diff = 0;		// long
	user -> efa = 0;		// long 
	user -> fvb = 0.00;		// double 2 stellennachdemkomma
	user -> fvbso = 0.00;		// double 2 stellennachdemkomma
	user -> fvbz = 0;		// long
	user -> fvbzso = 0;		// long
	user -> gfb = 0;		// long
	user -> hbalte = 0;		// long
	user -> hfvb = 0;		// long
	user -> hfvbz = 0.00;		// double 2 stellennachdemkomma
	user -> hfvbzso = 0.00;		// double 2 stellennachdemkomma
	user -> hoch = 0;		// long
	user -> j = 0;			// int
	user -> jbmg = 0;		// long
	user -> jlfreib = 0.00;		// double 2 stellennachdemkomma 
	user -> jlhinzu = 0.00;		// double 2 stellennachdemkomma
	user -> jw = 0;			// long
	user -> k = 0;			// int
	user -> kennvmt = 0;		// int 
	user -> kfb = 0;		// long
	user -> kvsatzag = 0.00000;	// double 5 stellennachdemkomma
	user -> kvsatzan = 0.00000;	// double 5 stellennachdemkomma
	user -> kztab = 0;		// int
	user -> lstjahr = 0;		// long
	user -> lst1 = 0;		// long
	user -> lst2 = 0;		// long
	user -> lst3 = 0;		// long
	user -> lstoso = 0;		// long
	user -> lstso = 0;		// long
	user -> mist = 0;		// long
       	user -> pvsatzag = 0.00000;	// double 5 stellennachdemkomma
	user -> pvsatzan = 0.00000;	// double 5 stellennachdemkomma
	user -> rvsatzan = 0.0000;	// double 4 stellennachdemkomma
	user -> rw = 0.0;		// double gleitkommadarstellung
	user -> sap = 0;		// long
	user -> solzfrei = 0;		// long
	user -> solzj = 0.00;		// double 2 stellennachdemkomma 
	user -> solzmin = 0.00;		// double 2 stellennachdemkomma
	user -> st = 0;			// long
	user -> st1 = 0;		// long
	user -> st2 = 0;		// long
	user -> stovmt = 0;		// long
	user -> tab1 = 0.0;		// double 
	user -> tab2 = 0;		// long
	user -> tab3 = 0;		// long
	user -> tab4 = 0.0;		// double
	user -> tab5 = 0;		// long
	user -> tbsvorv = 0.00;		// double 2 stellennachdemkomma
	user -> vbezb = 0;		// long
	user -> vbezbso = 0;		// long
	user -> vergl = 0;		// long
	user -> vhb = 0.00;		// double 2 stellennachdemkomma
	user -> vkv = 0;		// long
	user -> vsp = 0.00;		// double 2 stellennachdemkomma
	user -> vspn = 0.00;		// double 2 stellennachdemkomma
	user -> vsp1 = 0.00;		// double 2 stellennachdemkomma
	user -> vsp2 = 0.00;		// double 2 stellennachdemkomma 
	user -> vsp3 = 0.00;		// double 2 stellennachdemkomma
	user -> w1stkl5 = 0;		// long
	user -> w2stkl5 = 0;		// long
	user -> w3stkl5 = 0;		// long
	user -> x = 0.00;		// double 2 stellennachdemkomma
	user -> y = 0.000000;		// double 6 stellennachdemkomma
	user -> zre4 = 0.00;		// double 2 stellennachdemkomma
	user -> zre4j = 0.00;		// double 2 stellenanchdemkomma
	user -> zre4vp = 0.00;		// double 2 stellennachdemkomma
	user -> ztabfb = 0.00;		// double 2 stellennachdemkomma
	user -> zvbez = 0.00;		// double 2 stellennachdemkomma
	user -> zvbezj = 0.00;		// double 2 stellennachdemkomma
	user -> zve = 0.00;		// double 2 stellennachdemkomma 
	user -> zx = 0;			// long
	user -> zzx = 0;		// long

// ---------------------------------------------------------------------------------------------------------------
// eigene Felder
// ---------------------------------------------------------------------------------------------------------------

	user -> rv = 0.0;		// double
	user -> av = 0.0;		// double
	user -> kv = 0.0;		// double
	user -> pv_an = 0.0;		// double
	user -> pv_ag = 0.0;		// double
	user -> kst = 0.0;		// double
	user -> gesamt_st = 0.0;	// double
	user -> sum_sozialv_an = 0.0;	// double
	user -> sum_sozialv_ag = 0.0;	// double	
	user -> netto_lohn = 0.0;	// double
	user -> gesamt_belast_ag = 0.0;	// double 

// ---------------------------------------------------------------------------------------------------------------
// ID Feld
// ---------------------------------------------------------------------------------------------------------------

	user -> id_nummer = 0;		// long

	return user;

}
