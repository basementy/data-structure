<template>
  <div class="search__content">
    <h1>String Search Simulator</h1>
    <div class="text__content">
      {{ text }}
    </div>
  </div>
</template>

<script>
export default {
  name: 'Search',

  props: {
    text: String,
  },

  created() {
    if (!this.text) this.$router.replace({ name: 'home' });

    console.log(this.text);
  },
};
</script>

<style lang="scss" scoped>
.text__content {
  font-size: 18px;
  margin-top: 20px;
  text-align: justify;
}
</style>
