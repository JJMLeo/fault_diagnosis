#ifndef __c83_TSE_Path_h__
#define __c83_TSE_Path_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc83_TSE_PathInstanceStruct
#define typedef_SFc83_TSE_PathInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c83_sfEvent;
  boolean_T c83_isStable;
  boolean_T c83_doneDoubleBufferReInit;
  uint8_T c83_is_active_c83_TSE_Path;
  real_T *c83_WG6;
  real_T *c83_T6s;
  real_T *c83_WcoolPT;
  real_T *c83_T3s;
  real_T *c83_T6snew;
  real_T *c83_Wf;
  real_T *c83_WG6new;
  real_T *c83_h6new;
  real_T *c83_f;
} SFc83_TSE_PathInstanceStruct;

#endif                                 /*typedef_SFc83_TSE_PathInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c83_TSE_Path_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c83_TSE_Path_get_check_sum(mxArray *plhs[]);
extern void c83_TSE_Path_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
