<template>
    <div class="home__content">
      <h1>String Search Simulator</h1>
      <file-uploader @fileLoaded="startSearch" />
    </div>
</template>

<script>
import FileUploader from '@/components/FileUploader.vue';

export default {
  name: 'Home',

  components: {
    FileUploader,
  },

  methods: {
    startSearch(event) {
      const text = event;
      this.$router.push({ name: 'search', params: { text } });
    },
  },
};
</script>

<style lang="scss" scoped>
.home__content {
  width: 100%;
  height: 100%;
  display: flex;
  flex-direction: column;
  justify-content: center;
  align-items: center;
}
</style>
