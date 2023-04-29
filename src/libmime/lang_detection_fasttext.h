/*-
 * Copyright 2023 Vsevolod Stakhov
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef RSPAMD_LANG_DETECTION_FASTTEXT_H
#define RSPAMD_LANG_DETECTION_FASTTEXT_H

#include "config.h"

G_BEGIN_DECLS
struct rspamd_config;
/**
 * Initialize fasttext language detector
 * @param cfg
 * @return opaque pointer
 */
void* rspamd_lang_detection_fasttext_init(struct rspamd_config *cfg);


typedef  void * rspamd_fasttext_predict_result_t;
/**
 * Detect language using fasttext
 * @param ud opaque pointer
 * @param in input text
 * @param len length of input text
 * @param k number of results to return
 * @return TRUE if language is detected
 */
rspamd_fasttext_predict_result_t rspamd_lang_detection_fasttext_detect(void *ud,
		const char *in, size_t len, int k);

/**
 * Get language from fasttext result
 * @param res
 * @return
 */
const char *rspamd_lang_detection_fasttext_get_lang(rspamd_fasttext_predict_result_t res);

/**
 * Get probability from fasttext result
 * @param res
 * @return
 */
float rspamd_lang_detection_fasttext_get_prob(rspamd_fasttext_predict_result_t res);

/**
 * Destroy fasttext result
 * @param res
 */
void rspamd_fasttext_predict_result_destroy(rspamd_fasttext_predict_result_t res);

/**
 * Destroy fasttext language detector
 */
void rspamd_lang_detection_fasttext_destroy(void *ud);


G_END_DECLS
#endif /* RSPAMD_LANG_DETECTION_FASTTEXT_H */
