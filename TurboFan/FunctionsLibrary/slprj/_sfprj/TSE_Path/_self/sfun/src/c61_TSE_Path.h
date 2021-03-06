#ifndef __c61_TSE_Path_h__
#define __c61_TSE_Path_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc61_TSE_PathInstanceStruct
#define typedef_SFc61_TSE_PathInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c61_sfEvent;
  boolean_T c61_isStable;
  boolean_T c61_doneDoubleBufferReInit;
  uint8_T c61_is_active_c61_TSE_Path;
  real_T *c61_WG5;
  real_T *c61_T5s;
  real_T *c61_WcoolGT;
  real_T *c61_T3s;
  real_T *c61_T5snew;
  real_T *c61_Wf;
  real_T *c61_WG5new;
  real_T *c61_h5new;
} SFc61_TSE_PathInstanceStruct;

#endif                                 /*typedef_SFc61_TSE_PathInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c61_TSE_Path_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c61_TSE_Path_get_check_sum(mxArray *plhs[]);
extern void c61_TSE_Path_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
