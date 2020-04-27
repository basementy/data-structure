<template>
  <div class="search__container">
    <h1>String Search Simulator</h1>
    <input class="search__input" type="text" placeholder="Insert the pattern" v-model="pattern">
    <div class="search__content">
      <div class="search__content--text--wrapper">
        <p
          class="search__content--text"
          :class="{'search__content--match': isMatched(index)}"
          v-for="(char, index) in textArray"
          :key="index + char"
        >
          {{ char }}
        </p>
      </div>
      <div class="search__content--pattern--wrapper" :style="patternPosition">
        <div class="search__content--pattern" v-for="(char, index) in pattern" :key="index + char">
          {{ char}}
        </div>
      </div>
    </div>
  </div>
</template>

<script>
export default {
  name: 'Search',

  props: {
    text: String,
  },

  data: () => ({
    pattern: null,
    matches: [],
    position: 0,
  }),

  created() {
    if (!this.text) this.$router.replace({ name: 'home' });
  },

  watch: {
    patternPosition() {
      const element = this.$el.querySelector('.search__content');
      element.scrollLeft = 36 * this.position;
    },
  },

  computed: {
    textArray() {
      return this.text?.split('');
    },

    patternPosition() {
      return `padding-left: ${36 * this.position}px;`;
    },
  },

  methods: {
    isMatched(char) {
      return !!this.matches.some((index) => index === char);
    },
  },
};
</script>

<style lang="scss" scoped>
.search__container {
  .search__input {
    width: 100%;
    height: 62px;
    border: none;
    outline: none;
    font-size: 18px;
    text-align: center;
    margin: 10px 0px;
  }

  .search__content {
    width: 100%;
    max-width: 720px;
    height: 100px;
    overflow: auto;
    display: flex;
    flex-wrap: nowrap;
    font-size: 18px;
    margin-top: 20px;
    text-align: justify;
    flex-direction: column;

    &::-webkit-scrollbar {
      width: 6px;
      height: 8px;
      background-color: #F5F5F5;
    }

    &::-webkit-scrollbar-thumb {
      background-color: #ebebeb;
    }

    .search__content--text--wrapper {
      width: auto;
      display: flex;

      .search__content--text {
        width: 20px;
        height: 20px;
        padding: 15px;
        margin: 2px;
        display: flex;
        justify-content: center;
        align-items: center;
        border: 1px solid rgb(173, 173, 173);
        border-radius: 3px;

        &.search__content--match {
          background: rgb(167, 90, 255);
          color: #fff;
          border: 1px solid rgb(167, 90, 255);
        }
      }
    }

    .search__content--pattern--wrapper {
      width: auto;
      display: flex;

      .search__content--pattern {
        position: relative;
        width: 20px;
        height: 20px;
        padding: 15px;
        margin: 2px;
        display: flex;
        justify-content: center;
        align-items: center;
        border: 1px solid rgb(173, 173, 173);
        border-radius: 3px;
      }
    }
  }
}
</style>
