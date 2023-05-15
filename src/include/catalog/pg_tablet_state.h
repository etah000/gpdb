/*-------------------------------------------------------------------------
 *
 * pg_tablet_state.h
 *    define tablets' state for each table.
 *
 *
 * IDENTIFICATION
 *	    src/include/catalog/pg_tablet_state.h
 *
 *-------------------------------------------------------------------------
 */
#ifndef PG_TABLET_STATE_H
#define PG_TABLET_STATE_H

#include "catalog/genbki.h"
#include "catalog/pg_tablet_state_d.h"

#define PG_TABLET_STATE_STATE_NORMAL 'n'
#define PG_TABLET_STATE_STATE_REBALANCE 'r'


CATALOG(pg_tablet_state,7172,TabletStateRelationId)
{
	Oid		table_id;
	int16	tablet_id;
	int16   segment_id;
	int16   target_segment_id;
	char	status;
} FormData_pg_tablet_state;

FOREIGN_KEY(table_id REFERENCES pg_class(oid));
FOREIGN_KEY(segment_id REFERENCES gp_segment_configuration(dbid));


typedef FormData_pg_tablet_state *Form_pg_tablet_state;


#endif /*_PG_TABLET_STATE_H_*/
