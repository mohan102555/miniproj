/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _EMPLOYEE_H_RPCGEN
#define _EMPLOYEE_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct details {
	char name[20];
	int id;
	char phone[15];
	char city[20];
	int pincode;
};
typedef struct details details;

#define employee_prog 0x99999999
#define employee_vers 1

#if defined(__STDC__) || defined(__cplusplus)
#define operation1 1
extern  char ** operation1_1(struct details *, CLIENT *);
extern  char ** operation1_1_svc(struct details *, struct svc_req *);
#define operation2 2
extern  char ** operation2_1(char **, CLIENT *);
extern  char ** operation2_1_svc(char **, struct svc_req *);
#define operation3 3
extern  char ** operation3_1(char **, CLIENT *);
extern  char ** operation3_1_svc(char **, struct svc_req *);
#define operation4 4
extern  char ** operation4_1(char **, CLIENT *);
extern  char ** operation4_1_svc(char **, struct svc_req *);
#define operation5 5
extern  char ** operation5_1(char **, CLIENT *);
extern  char ** operation5_1_svc(char **, struct svc_req *);
extern int employee_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define operation1 1
extern  char ** operation1_1();
extern  char ** operation1_1_svc();
#define operation2 2
extern  char ** operation2_1();
extern  char ** operation2_1_svc();
#define operation3 3
extern  char ** operation3_1();
extern  char ** operation3_1_svc();
#define operation4 4
extern  char ** operation4_1();
extern  char ** operation4_1_svc();
#define operation5 5
extern  char ** operation5_1();
extern  char ** operation5_1_svc();
extern int employee_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_details (XDR *, details*);

#else /* K&R C */
extern bool_t xdr_details ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_EMPLOYEE_H_RPCGEN */
