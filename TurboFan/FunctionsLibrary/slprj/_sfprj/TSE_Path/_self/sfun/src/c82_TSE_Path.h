#ifndef __c82_TSE_Path_h__
#define __c82_TSE_Path_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc82_TSE_PathInstanceStruct
#define typedef_SFc82_TSE_PathInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c82_sfEvent;
  boolean_T c82_isStable;
  boolean_T c82_doneDoubleBufferReInit;
  uint8_T c82_is_active_c82_TSE_Path;
  real_T *c82_T5s;
  real_T *c82_WG5;
  real_T *c82_WcoolPT;
  real_T *c82_T3s;
  real_T *c82_T5snew;
  real_T *c82_Wf;
  real_T *c82_Sfcn5new;
} SFc82_TSE_PathInstanceStruct;

#endif                                 /*typedef_SFc82_TSE_PathInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c82_TSE_Path_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c82_TSE_Path_get_check_sum(mxArray *plhs[]);
extern void c82_TSE_Path_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
