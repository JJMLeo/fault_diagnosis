#ifndef __c1_TSE_Path_h__
#define __c1_TSE_Path_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_TSE_PathInstanceStruct
#define typedef_SFc1_TSE_PathInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  boolean_T c1_isStable;
  boolean_T c1_doneDoubleBufferReInit;
  uint8_T c1_is_active_c1_TSE_Path;
  real_T *c1_f;
  real_T *c1_PRPT;
  real_T *c1_EFPT;
  real_T *c1_T6s;
  real_T *c1_T51s;
  real_T *c1_h6;
  real_T *c1_Sfcn6;
  real_T *c1_Sfcn51;
  real_T *c1_DHT_T;
} SFc1_TSE_PathInstanceStruct;

#endif                                 /*typedef_SFc1_TSE_PathInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_TSE_Path_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_TSE_Path_get_check_sum(mxArray *plhs[]);
extern void c1_TSE_Path_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
