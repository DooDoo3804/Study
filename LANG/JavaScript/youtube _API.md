## youtube API

```vue
<template>
  <div class="vuetube-wrap">
    <div class="container">
      <div class="d-flex justify-content-center flex-column">
        <h1 class="m-3 text-primary text-center">SSAFY TUBE</h1>
        <section v-if="isSelectedVideo" class="mt-2">
          <div class="ratio ratio-16x9">
            <iframe :src="videoSrc" frameborder="0"></iframe>
          </div>
          <div class="detail">
            <b>{{ videoTitle }}</b>
          </div>
        </section>
      </div>
    </div>
  </div>
</template>

<script>
import axios from 'axios'
import _ from 'lodash'

import 'bootstrap/dist/css/bootstrap.css'
import 'bootstrap-vue/dist/bootstrap-vue.css'

const URL = 'https://www.googleapis.com/youtube/v3/search'
const API_KEY = 'AIzaSyDU_rNwP9r8rdXHdoKf-hVl7eiH0iGwjKk'

export default {
  name: 'App',
  created() {
    axios.get(URL, {
      params: {
        key: API_KEY,
        type: 'video',
        part: 'snippet',
        q: '2pm',
      }
    })
     .then(result => {
      this.videos = result.data.items
      this.selectedVideo = this.videos[0]
    })
      .catch(error => {
        console.log(error)
      })
  }
  ,data() {
    return {
      videos: [],
      selectedVideo: {},
    }
  }
  ,computed: {
    videoSrc() {
      console.log(this.selectedVideo.id_videoId)
      return `https://youtube.com/embed/${this.selectedVideo.id.videoId}`
      },
    videoTitle() {
      return _.unescape(this.selectedVideo.snippet.title)
      },
    isSelectedVideo() {
      return !!Object.keys(this.selectedVideo).length
    }
  }
}
</script>

<style>

</style>
```

